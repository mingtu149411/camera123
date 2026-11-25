// 作者：南京大学24届沈逸文
#include "CameraRefinementNative.h"
#include "CameraRefinementNativeState.h"
#include "CameraRefinementData.h"
#include "CameraRefinementSettings.h"
#include "Camera/CameraActor.h"
#include "Camera/CameraComponent.h"
#include "Camera/PlayerCameraManager.h"
#include "GameFramework/PlayerController.h"
#include "Engine/PostProcessVolume.h"
#include "Engine/TextureRenderTarget2D.h"
#include "Engine/World.h"
#include "Components/BrushComponent.h"
#include "PhysicsEngine/BodySetup.h"
#include "PhysicsEngine/ConvexElem.h"
#include "SceneViewExtension.h"
#include "SceneView.h"
#include "SceneInterface.h"
#include "StereoRendering.h"
#include "PostProcess/PostProcessMaterialInputs.h"
#include "GlobalShader.h"
#include "ShaderParameterStruct.h"
#include "RenderGraphUtils.h"
#include "ScreenPass.h"
#include "SystemTextures.h"
#include "TextureResource.h"
#include "UObject/StrongObjectPtr.h"
#include "UObject/UObjectIterator.h"

// The limits are explicit: never silently discard a volume or replace its brush by a box.
static constexpr int CRMaxPlanes=256, CRMaxHulls=32, CRMaxEdges=512;
struct FCRNativeFrame {
 TArray<FVector4f> Planes,Hulls,Edges;
 FVector3f Origin,Dx,Dy;
 FVector4f Radii=FVector4f(0,0,0,0);
 int32 Count=0;
 TArray<FTextureRHIRef> Colors;
};
class FCRNativeComposite : public FGlobalShader {
 DECLARE_GLOBAL_SHADER(FCRNativeComposite);
 SHADER_USE_PARAMETER_STRUCT(FCRNativeComposite,FGlobalShader);
 BEGIN_SHADER_PARAMETER_STRUCT(FParameters,)
  SHADER_PARAMETER(FVector2f,OutputMin)
  SHADER_PARAMETER(FVector2f,OutputSize)
  SHADER_PARAMETER(FVector2f,InputMinUV)
  SHADER_PARAMETER(FVector2f,InputSizeUV)
  SHADER_PARAMETER(FVector3f,Origin)
  SHADER_PARAMETER(FVector3f,Dx)
  SHADER_PARAMETER(FVector3f,Dy)
  SHADER_PARAMETER(FVector4f,Radii)
  SHADER_PARAMETER(uint32,VolumeCount)
  SHADER_PARAMETER(uint32,HullCount)
  SHADER_PARAMETER_ARRAY(FVector4f,Planes,[256])
  SHADER_PARAMETER_ARRAY(FVector4f,Hulls,[32])
  SHADER_PARAMETER_ARRAY(FVector4f,Edges,[1024])
  SHADER_PARAMETER_RDG_TEXTURE(Texture2D,SceneColor)
  SHADER_PARAMETER_RDG_TEXTURE(Texture2D,Color1)
  SHADER_PARAMETER_RDG_TEXTURE(Texture2D,Color2)
  SHADER_PARAMETER_RDG_TEXTURE(Texture2D,Color3)
  SHADER_PARAMETER_RDG_TEXTURE(Texture2D,Color4)
  SHADER_PARAMETER_RDG_TEXTURE(Texture2D,Color5)
  SHADER_PARAMETER_RDG_TEXTURE(Texture2D,Color6)
  SHADER_PARAMETER_RDG_TEXTURE(Texture2D,Color7)
  SHADER_PARAMETER_SAMPLER(SamplerState,ColorSampler)
  RENDER_TARGET_BINDING_SLOTS()
 END_SHADER_PARAMETER_STRUCT()
 static bool ShouldCompilePermutation(const FGlobalShaderPermutationParameters& P){return IsFeatureLevelSupported(P.Platform,ERHIFeatureLevel::SM5);}
};
IMPLEMENT_GLOBAL_SHADER(FCRNativeComposite,"/Plugin/CameraRefinement/NativeVolumes.usf","MainPS",SF_Pixel);

static UCameraComponent* CRCamera(const FSceneView& V){
 AActor* A=const_cast<AActor*>(V.ViewActor.Get());
 if(auto C=Cast<ACameraActor>(A))return C->GetCameraComponent();
 if(A){TInlineComponentArray<UCameraComponent*> Cameras;A->GetComponents(Cameras);for(auto C:Cameras)if(C->IsActive())return C;}
 return nullptr;
}
static float CRWeight(IInterface_PostProcessVolume* V,const FVector& P){
 const auto S=V->GetProperties();if(!S.bIsEnabled)return 0;
 float W=FMath::Clamp(S.BlendWeight,0.f,1.f);
 if(!S.bIsUnbound){float D=0;V->EncompassesPoint(P,0,&D);if(D<0||D>S.BlendRadius)return 0;if(S.BlendRadius>=1)W*=1-D/S.BlendRadius;}
 return W;
}
// Intersect a convex hull with the actual near-plane rectangle in UV space.
static bool CRPatchIntersects(const TArray<FPlane>& Planes,const FCameraRefinementFrame& F){
 TArray<FVector2D> Poly={{0,0},{1,0},{1,1},{0,1}};
 for(const auto& P:Planes){
  TArray<FVector2D> Next;
  for(int I=0;I<Poly.Num();I++){
   auto A=Poly[I],B=Poly[(I+1)%Poly.Num()];double DA=P.PlaneDot(F.At(A)),DB=P.PlaneDot(F.At(B));
   if(DA<=0.00001)Next.Add(A);
   if((DA<0)!=(DB<0))Next.Add(A+(B-A)*(DA/(DA-DB)));
  }
  Poly=MoveTemp(Next);if(!Poly.Num())return false;
 }
 return true;
}
static bool CRGeometry(APostProcessVolume* V,const FVector& CameraOrigin,const FCameraRefinementFrame& Near,int Region,FCRNativeFrame& Out,bool& Intersects,bool& Contains){
 auto Brush=V->GetBrushComponent();auto Body=Brush?Brush->GetBodySetup():nullptr;
 if(!Body||!Body->AggGeom.ConvexElems.Num())return false;
 Intersects=false;Contains=false;
 for(const auto& Hull:Body->AggGeom.ConvexElems){
  TArray<FPlane> Local;Hull.GetPlanes(Local);if(!Local.Num())return false;
  FTransform Transform=Hull.GetTransform()*Brush->GetComponentTransform();Transform.AddToTranslation(-CameraOrigin);
  const FMatrix Matrix=Transform.ToMatrixWithScale();TArray<FPlane> Planes;
  for(const auto& P:Local)Planes.Add(P.TransformBy(Matrix));
  Intersects|=CRPatchIntersects(Planes,Near);
  bool All=true;for(auto UV:{FVector2D(0,0),FVector2D(1,0),FVector2D(0,1),FVector2D(1,1)})for(const auto& P:Planes)All&=P.PlaneDot(Near.At(UV))<=0.00001;
  Contains|=All;
  if(Out.Hulls.Num()>=CRMaxHulls||Out.Planes.Num()+Planes.Num()>CRMaxPlanes)return false;
  int PO=Out.Planes.Num(),EO=Out.Edges.Num()/2;
  for(auto P:Planes){double L=FVector(P.X,P.Y,P.Z).Length();if(L<1.e-12)return false;Out.Planes.Add(FVector4f(P.X/L,P.Y/L,P.Z/L,P.W/L));}
  TSet<uint64> Seen;
  for(int I=0;I+2<Hull.IndexData.Num();I+=3)for(int J=0;J<3;J++){
   uint32 A=Hull.IndexData[I+J],B=Hull.IndexData[I+(J+1)%3];if(A>B)Swap(A,B);uint64 Key=(uint64(A)<<32)|B;
   if(Seen.Contains(Key))continue;Seen.Add(Key);
   if(!Hull.VertexData.IsValidIndex(A)||!Hull.VertexData.IsValidIndex(B)||Out.Edges.Num()/2>=CRMaxEdges)return false;
   Out.Edges.Add(FVector4f(FVector3f(Transform.TransformPosition(Hull.VertexData[A])),0));Out.Edges.Add(FVector4f(FVector3f(Transform.TransformPosition(Hull.VertexData[B])),0));
  }
  // Pack edge start/count into W (10 bits each), plane start/count and region in XYZ.
  Out.Hulls.Add(FVector4f(PO,Planes.Num(),Region,EO+1024*(Out.Edges.Num()/2-EO)));
 }
 return true;
}

class FCameraRefinementViewExtension : public FSceneViewExtensionBase {
 TMap<const void*,FCRNativeFrame> Frames; // render-thread only
 TMap<const void*,TStrongObjectPtr<UCameraRefinementNativeState>> States; // game-thread only
 TFunction<void(FSceneView&)> Forced;
 static const void* Key(const FSceneView& V){return V.State?static_cast<const void*>(V.State):static_cast<const void*>(V.Family->RenderTarget);}
 void Status(const FString& Text,int Extra=0){auto S=GetMutableDefault<UCameraRefinementSettings>();S->NativeStatus=Text;S->NativeExtraRenders=Extra;}
public:
 FCameraRefinementViewExtension(const FAutoRegister& A):FSceneViewExtensionBase(A){}
 virtual void SetupViewFamily(FSceneViewFamily&)override{}
 virtual void BeginRenderViewFamily(FSceneViewFamily&)override{}
 virtual void SetupView(FSceneViewFamily& Family,FSceneView& View)override{
  if(Forced){Forced(View);View.FinalPostProcessSettings.UserFlags|=0x40000000;return;}
  const void* K=Key(View);ENQUEUE_RENDER_COMMAND(CRClear)([this,K](FRHICommandListImmediate&){Frames.Remove(K);});
  auto Camera=CRCamera(View);bool Enabled=UCameraRefinementLibrary::IsRefinementEnabled(Camera);
  if(Enabled)View.FinalPostProcessSettings.UserFlags|=0x40000000;else View.FinalPostProcessSettings.UserFlags&=~0x40000000;
  if(!Enabled||!GetDefault<UCameraRefinementSettings>()->bNativeVolumes){Status(TEXT("关闭：保留引擎默认判定"));return;}
  if(View.StereoPass!=EStereoscopicPass::eSSP_FULL||View.GetFeatureLevel()<ERHIFeatureLevel::SM5||Family.EngineShowFlags.PathTracing){Status(TEXT("回退：当前立体/移动/路径追踪视图未适配"));return;}
  if(View.bIsSceneCapture&&Family.SceneCaptureSource!=SCS_FinalColorLDR&&Family.SceneCaptureSource!=SCS_FinalColorHDR&&Family.SceneCaptureSource!=SCS_FinalToneCurveHDR)return;
  UWorld* World=Family.Scene?Family.Scene->GetWorld():nullptr;if(!World||!View.IsPerspectiveProjection()&&View.UnscaledViewRect.IsEmpty())return;
  const FVector CameraOrigin=View.ViewMatrices.GetViewOrigin();
  auto Near=FCameraRefinementFrame::FromMatrices(View.ViewMatrices.GetProjectionMatrix(),View.ViewMatrices.GetInvViewMatrix());
  FBox Patch(ForceInit);for(auto UV:{FVector2D(0,0),FVector2D(1,0),FVector2D(0,1),FVector2D(1,1)})Patch+=Near.At(UV)+CameraOrigin;
  FCRNativeFrame Frame;Frame.Origin=FVector3f(Near.Origin);Frame.Dx=FVector3f(Near.Dx);Frame.Dy=FVector3f(Near.Dy);
  TArray<IInterface_PostProcessVolume*> Variable;bool ConstantChanged=false;
  for(auto V:World->PostProcessVolumes){
   const auto P=V->GetProperties();if(!P.bIsEnabled||P.bIsUnbound||P.BlendWeight<=0)continue;
   ConstantChanged|=FMath::Abs(CRWeight(V,CameraOrigin)-CRWeight(V,CameraOrigin+Near.At(FVector2D(.5,.5))))>1.e-6;
   auto Volume=Cast<APostProcessVolume>(V->_getUObject());
   if(!Volume){
    float D=0;V->EncompassesPoint(CameraOrigin+Near.At(FVector2D(.5,.5)),0,&D);
    const float PatchRadius=.5*(Near.Dx.Length()+Near.Dy.Length());
    if(D<0||D>P.BlendRadius+PatchRadius)continue;
    Status(TEXT("回退：邻近自定义体积接口没有可读取的原生凸包"));return;
   }
   if(!Volume->GetComponentsBoundingBox(true).ExpandBy(P.BlendRadius+0.001).Intersect(Patch))continue;
   FCRNativeFrame Geometry;bool Hit=false,All=false;
   if(!CRGeometry(Volume,CameraOrigin,Near,Variable.Num(),Geometry,Hit,All)){Status(TEXT("回退：凸包未就绪或超过几何预算"));return;}
   if(All||(!Hit&&P.BlendRadius<=0))continue;
   if(Variable.Num()>=3 || (1<<(Variable.Num()+1))>GetDefault<UCameraRefinementSettings>()->MaxNativeProfiles){Status(TEXT("回退：同时跨越的官方体积超过原生渲染预算"));return;}
   if(Frame.Planes.Num()+Geometry.Planes.Num()>CRMaxPlanes||Frame.Hulls.Num()+Geometry.Hulls.Num()>CRMaxHulls||Frame.Edges.Num()+Geometry.Edges.Num()>2*CRMaxEdges){Status(TEXT("回退：体积几何超出 256 平面/32 凸包/512 边预算"));return;}
   for(auto H:Geometry.Hulls){H.X+=Frame.Planes.Num();H.W+=Frame.Edges.Num()/2;Frame.Hulls.Add(H);}
   Frame.Planes.Append(Geometry.Planes);Frame.Edges.Append(Geometry.Edges);Frame.Radii[Variable.Num()]=P.BlendRadius;Variable.Add(V);
  }
  if(!Variable.Num()&&!ConstantChanged){Status(TEXT("未跨越官方体积边界：无需额外渲染"));return;}
  Frame.Count=Variable.Num();const int Profiles=1<<Frame.Count;
  // Copy a view and initialize engine defaults without a world. Scene objects remain untouched.
  FSceneView Scratch(View);
  FSceneViewFamilyContext Neutral(FSceneViewFamily::ConstructionValues(Family.RenderTarget,nullptr,Family.EngineShowFlags).SetTime(Family.Time));
  Scratch.Family=&Neutral;Scratch.StartFinalPostprocessSettings(CameraOrigin);Scratch.Family=&Family;
  const FFinalPostProcessSettings Base=Scratch.FinalPostProcessSettings;
  FSceneViewInitOptions Options;Options.ViewFamily=&Family;Options.SetViewRectangle(View.UnscaledViewRect);
  USceneCaptureComponent2D* SourceCapture=nullptr;
  if(View.bIsSceneCapture)for(TObjectIterator<USceneCaptureComponent2D> It;It;++It)if(It->GetWorld()==World&&It->GetViewState(0)==View.State){SourceCapture=*It;break;}
  auto& Stored=States.FindOrAdd(K);if(!Stored.IsValid()){Stored=TStrongObjectPtr<UCameraRefinementNativeState>(NewObject<UCameraRefinementNativeState>());Stored->World=World;}
  auto State=Stored.Get();const FIntPoint Size=View.UnscaledViewRect.Size();
  while(State->Captures.Num()<Profiles-1){
   auto C=NewObject<USceneCaptureComponent2D>(State);C->bCaptureEveryFrame=false;C->bCaptureOnMovement=false;C->bAlwaysPersistRenderingState=true;C->RegisterComponentWithWorld(World);State->Captures.Add(C);
   auto T=NewObject<UTextureRenderTarget2D>(State);T->RenderTargetFormat=RTF_RGBA16f;T->bForceLinearGamma=true;T->bAutoGenerateMips=false;State->Targets.Add(T);C->TextureTarget=T;
  }
  TArray<FTextureRenderTargetResource*> Resources;
  FFinalPostProcessSettings MainSettings;
  auto BuildSettings=[&](int I,FSceneViewStateInterface* ProfileState){
   Scratch.State=ProfileState;
   Scratch.FinalPostProcessSettings=Base;
   for(auto V:World->PostProcessVolumes){const auto P=V->GetProperties();int Index=Variable.Find(V);float W=Index==INDEX_NONE?CRWeight(V,CameraOrigin+Near.At(FVector2D(.5,.5))):((I&(1<<Index))?FMath::Clamp(P.BlendWeight,0.f,1.f):0);if(W>0&&P.Settings)Scratch.OverridePostProcessSettings(*P.Settings,W);}
   if(SourceCapture)Scratch.OverridePostProcessSettings(SourceCapture->PostProcessSettings,SourceCapture->PostProcessBlendWeight);
   else if(World->IsGameWorld()&&World->GetFirstPlayerController()&&World->GetFirstPlayerController()->PlayerCameraManager){
    auto Manager=World->GetFirstPlayerController()->PlayerCameraManager;
    TArray<FPostProcessSettings> const* Blends=nullptr;TArray<float> const* Weights=nullptr;TArray<EViewTargetBlendOrder> const* Orders=nullptr;
    Manager->GetCachedPostProcessBlends(Blends,Weights,Orders);
    if(Blends&&Weights&&Orders)for(int J=0;J<Blends->Num();J++)if((*Orders)[J]==VTBlendOrder_Base)Scratch.OverridePostProcessSettings((*Blends)[J],(*Weights)[J]);
    const auto& POV=Manager->GetCameraCacheView();Scratch.OverridePostProcessSettings(POV.PostProcessSettings,POV.PostProcessBlendWeight);
    if(Blends&&Weights&&Orders)for(int J=0;J<Blends->Num();J++)if((*Orders)[J]==VTBlendOrder_Override)Scratch.OverridePostProcessSettings((*Blends)[J],(*Weights)[J]);
    Manager->UpdatePhotographyPostProcessing(Scratch.FinalPostProcessSettings);
   }
   else if(Camera)Scratch.OverridePostProcessSettings(Camera->PostProcessSettings,Camera->PostProcessBlendWeight);
   Scratch.EndFinalPostprocessSettings(Options);Scratch.FinalPostProcessSettings.UserFlags|=0x40000000;
   return Scratch.FinalPostProcessSettings;
  };
  MainSettings=BuildSettings(0,View.State);
  for(int I=1;I<Profiles;I++){
   auto C=State->Captures[I-1];auto T=State->Targets[I-1];
   if(T->SizeX!=Size.X||T->SizeY!=Size.Y){T->InitAutoFormat(FMath::Max(2,Size.X),FMath::Max(2,Size.Y));T->UpdateResourceImmediate(true);}
   T->TargetGamma=Family.RenderTarget->GetDisplayGamma();C->ShowFlags=Family.EngineShowFlags;C->UnlitViewmode=Family.EngineShowFlags.UnlitViewmode?ESceneCaptureUnlitViewmode::Capture:ESceneCaptureUnlitViewmode::Disabled;
   C->CaptureSource=View.bIsSceneCapture?Family.SceneCaptureSource:SCS_FinalColorLDR;
   if(C->CaptureSource!=SCS_FinalColorLDR&&C->CaptureSource!=SCS_FinalColorHDR&&C->CaptureSource!=SCS_FinalToneCurveHDR)C->CaptureSource=SCS_FinalColorLDR;
   C->ProjectionType=View.IsPerspectiveProjection()?ECameraProjectionMode::Perspective:ECameraProjectionMode::Orthographic;
   C->SetWorldLocationAndRotation(CameraOrigin,FRotationMatrix::MakeFromXZ(View.GetViewDirection(),View.GetViewUp()).ToQuat());
   C->bUseCustomProjectionMatrix=true;C->CustomProjectionMatrix=View.ViewMatrices.GetProjectionMatrix();
   if(SourceCapture){C->PrimitiveRenderMode=SourceCapture->PrimitiveRenderMode;C->ShowOnlyActors=SourceCapture->ShowOnlyActors;C->HiddenActors=SourceCapture->HiddenActors;C->ShowOnlyComponents=SourceCapture->ShowOnlyComponents;C->HiddenComponents=SourceCapture->HiddenComponents;}
   // Build after the capture's own StartFinalPostprocessSettings. Each profile uses
   // its own view state, so native blendable MIDs cannot overwrite another profile.
   Forced=[&](FSceneView& CaptureView){CaptureView.FinalPostProcessSettings=BuildSettings(I,CaptureView.State);};C->CaptureScene();Forced=nullptr;Resources.Add(T->GameThread_GetRenderTargetResource());
  }
  View.FinalPostProcessSettings=MainSettings;
  if(!Frame.Count){Status(TEXT("近裁剪平面统一使用原生参数：无需额外渲染"));return;}
  ENQUEUE_RENDER_COMMAND(CRFrame)([this,K,Frame=MoveTemp(Frame),Resources](FRHICommandListImmediate&)mutable{for(auto R:Resources)Frame.Colors.Add(R->GetRenderTargetTexture());Frames.Add(K,MoveTemp(Frame));});
  bool Soft=false;for(auto V:Variable)Soft|=V->GetProperties().BlendRadius>0;
  Status(Soft?TEXT("官方体积：原生完整画面按凸包距离混合（平滑区为输出插值）"):TEXT("官方体积：近裁剪平面逐像素分界"),Profiles-1);
 }
 virtual void SubscribeToPostProcessingPass(EPostProcessingPass Pass,const FSceneView& V,FPostProcessingPassDelegateArray& Callbacks,bool)override{
  if(Pass==EPostProcessingPass::Tonemap&&Frames.Contains(Key(V)))Callbacks.Add(FPostProcessingPassDelegate::CreateRaw(this,&FCameraRefinementViewExtension::Composite));
 }
 FScreenPassTexture Composite(FRDGBuilder& Graph,const FSceneView& V,const FPostProcessMaterialInputs& Inputs){
  const auto* F=Frames.Find(Key(V));if(!F)return Inputs.ReturnUntouchedSceneColorForPostProcessing(Graph);
  auto Source=FScreenPassTexture::CopyFromSlice(Graph,Inputs.GetInput(EPostProcessMaterialInput::SceneColor));
  FScreenPassRenderTarget Output=Inputs.OverrideOutput;if(!Output.IsValid())Output=FScreenPassRenderTarget::CreateFromInput(Graph,Source,V.GetOverwriteLoadAction(),TEXT("CRNativeOutput"));
  auto P=Graph.AllocParameters<FCRNativeComposite::FParameters>();P->OutputMin=FVector2f(Output.ViewRect.Min);P->OutputSize=FVector2f(Output.ViewRect.Size());P->InputMinUV=FVector2f(Source.ViewRect.Min)/FVector2f(Source.Texture->Desc.Extent);P->InputSizeUV=FVector2f(Source.ViewRect.Size())/FVector2f(Source.Texture->Desc.Extent);
  P->Origin=F->Origin;P->Dx=F->Dx;P->Dy=F->Dy;P->Radii=F->Radii;P->VolumeCount=F->Count;P->HullCount=F->Hulls.Num();
  for(int I=0;I<CRMaxPlanes;I++)P->Planes[I]=F->Planes.IsValidIndex(I)?F->Planes[I]:FVector4f(0,0,0,0);
  for(int I=0;I<CRMaxHulls;I++)P->Hulls[I]=F->Hulls.IsValidIndex(I)?F->Hulls[I]:FVector4f(0,0,0,0);
  for(int I=0;I<2*CRMaxEdges;I++)P->Edges[I]=F->Edges.IsValidIndex(I)?F->Edges[I]:FVector4f(0,0,0,0);
  auto External=[&](int I){return F->Colors.IsValidIndex(I)&&F->Colors[I].IsValid()?Graph.RegisterExternalTexture(CreateRenderTarget(F->Colors[I],TEXT("CRNativeProfile"))):GSystemTextures.GetBlackDummy(Graph);};
  P->SceneColor=Source.Texture;P->Color1=External(0);P->Color2=External(1);P->Color3=External(2);P->Color4=External(3);P->Color5=External(4);P->Color6=External(5);P->Color7=External(6);P->ColorSampler=TStaticSamplerState<SF_Bilinear,AM_Clamp,AM_Clamp>::GetRHI();P->RenderTargets[0]=Output.GetRenderTargetBinding();
  TShaderMapRef<FCRNativeComposite> Shader(GetGlobalShaderMap(V.GetFeatureLevel()));AddDrawScreenPass(Graph,RDG_EVENT_NAME("CameraRefinement NativeVolumes"),V,FScreenPassTextureViewport(Output),FScreenPassTextureViewport(Source),Shader,P);return Output;
 }
 void Release(UWorld* W){for(auto It=States.CreateIterator();It;++It)if(!W||It.Value()->World==W){for(auto C:It.Value()->Captures)if(IsValid(C))C->UnregisterComponent();It.RemoveCurrent();}ENQUEUE_RENDER_COMMAND(CRRelease)([this](FRHICommandListImmediate&){Frames.Empty();});FlushRenderingCommands();}
};
TSharedPtr<FCameraRefinementViewExtension,ESPMode::ThreadSafe> MakeCameraRefinementExtension(){return FSceneViewExtensions::NewExtension<FCameraRefinementViewExtension>();}
void ReleaseCameraRefinementWorld(const TSharedPtr<FCameraRefinementViewExtension,ESPMode::ThreadSafe>& E,UWorld* W){if(E)E->Release(W);}
void ShutdownCameraRefinement(const TSharedPtr<FCameraRefinementViewExtension,ESPMode::ThreadSafe>& E){if(E)E->Release(nullptr);}
