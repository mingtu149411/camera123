// 作者：南京大学24届沈逸文
using UnrealBuildTool;
public class CameraRefinementEditor : ModuleRules {
 public CameraRefinementEditor(ReadOnlyTargetRules Target) : base(Target) {
  PCHUsage=PCHUsageMode.UseExplicitOrSharedPCHs;
  PrivateDependencyModuleNames.AddRange(new[]{"Core","CoreUObject","Engine","CameraRefinement","UnrealEd","PropertyEditor","Slate","SlateCore","ToolMenus"});
 }
}
