// 作者：南京大学24届沈逸文
#include "CameraRefinementData.h"
#include "Camera/CameraComponent.h"
#include "CameraRefinementSettings.h"

bool UCameraRefinementLibrary::IsRefinementEnabled(UCameraComponent* Camera) {
 const bool Default=GetDefault<UCameraRefinementSettings>()->bDefaultEnabled;
 if (!Camera) return Default;
 auto* Data = Cast<UCameraRefinementData>(Camera->GetAssetUserDataOfClass(UCameraRefinementData::StaticClass()));
 return Data ? Data->bEnabled : Default;
}
void UCameraRefinementLibrary::SetRefinementEnabled(UCameraComponent* Camera, bool bEnabled) {
 if (!Camera) return;
 Camera->Modify();
 auto* Data = Cast<UCameraRefinementData>(Camera->GetAssetUserDataOfClass(UCameraRefinementData::StaticClass()));
 if (!Data) {
  Data = NewObject<UCameraRefinementData>(Camera, NAME_None, RF_Transactional);
  Camera->AddAssetUserData(Data);
 }
 Data->Modify();
 Data->bEnabled = bEnabled;
 Camera->MarkPackageDirty();
}
FCameraRefinementFrame FCameraRefinementFrame::FromMatrices(const FMatrix& Projection, const FMatrix& ViewRotationToWorld) {
 const FMatrix Inverse = Projection.Inverse();
 auto Point = [&](double X,double Y) {
  // UE reversed Z: clip Z=1 is the near plane, for perspective and orthographic.
  const FVector4 H = Inverse.TransformFVector4(FVector4(X,Y,1,1));
  return FVector(ViewRotationToWorld.TransformVector(FVector(H.X,H.Y,H.Z)/H.W));
 };
 FCameraRefinementFrame Frame;
 Frame.Origin=Point(-1,1); Frame.Dx=Point(1,1)-Frame.Origin; Frame.Dy=Point(-1,-1)-Frame.Origin;
 return Frame;
}
