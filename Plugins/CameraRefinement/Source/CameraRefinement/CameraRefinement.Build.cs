// 作者：南京大学24届沈逸文
using UnrealBuildTool;
public class CameraRefinement : ModuleRules {
 public CameraRefinement(ReadOnlyTargetRules Target) : base(Target) {
  PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
  PublicDependencyModuleNames.AddRange(new[]{"Core","CoreUObject","Engine","DeveloperSettings"});
  PrivateDependencyModuleNames.AddRange(new[]{"Projects","RenderCore","RHI","Renderer"});
 }
}
