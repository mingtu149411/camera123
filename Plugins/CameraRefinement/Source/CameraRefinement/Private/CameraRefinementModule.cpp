// 作者：南京大学24届沈逸文
#include "Modules/ModuleManager.h"
#include "Interfaces/IPluginManager.h"
#include "Misc/Paths.h"
#include "ShaderCore.h"
#include "Engine/World.h"
#include "CameraRefinementNative.h"
class FCameraRefinementModule : public IModuleInterface {
 TSharedPtr<FCameraRefinementViewExtension,ESPMode::ThreadSafe> Extension;
 FDelegateHandle Init,Cleanup;
public:
 virtual void StartupModule() override {
  const auto Plugin=IPluginManager::Get().FindPlugin(TEXT("CameraRefinement"));
  if(Plugin)AddShaderSourceDirectoryMapping(TEXT("/Plugin/CameraRefinement"),FPaths::Combine(Plugin->GetBaseDir(),TEXT("Shaders")));
  Init=FCoreDelegates::OnPostEngineInit.AddLambda([this](){Extension=MakeCameraRefinementExtension();});
  Cleanup=FWorldDelegates::OnWorldCleanup.AddLambda([this](UWorld* World,bool,bool){ReleaseCameraRefinementWorld(Extension,World);});
 }
 virtual void ShutdownModule() override {
  FCoreDelegates::OnPostEngineInit.Remove(Init);FWorldDelegates::OnWorldCleanup.Remove(Cleanup);
  ShutdownCameraRefinement(Extension);Extension.Reset();
 }
};
IMPLEMENT_MODULE(FCameraRefinementModule,CameraRefinement)
extern "C" CAMERAREFINEMENT_API const TCHAR* CameraRefinementAuthor(){return TEXT("南京大学24届沈逸文");}
