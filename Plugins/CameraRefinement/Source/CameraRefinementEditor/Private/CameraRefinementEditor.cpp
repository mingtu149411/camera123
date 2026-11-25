// 作者：南京大学24届沈逸文
#include "Modules/ModuleManager.h"
#include "PropertyEditorModule.h"
#include "IDetailCustomization.h"
#include "DetailLayoutBuilder.h"
#include "DetailCategoryBuilder.h"
#include "DetailWidgetRow.h"
#include "Widgets/Input/SCheckBox.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/SBoxPanel.h"
#include "Widgets/Text/STextBlock.h"
#include "Camera/CameraComponent.h"
#include "Camera/CameraActor.h"
#include "CameraRefinementData.h"
#include "ScopedTransaction.h"
#include "CameraRefinementSettings.h"
#include "ToolMenus.h"

class FCameraRefinementDetails : public IDetailCustomization {
 TArray<TWeakObjectPtr<UCameraComponent>> Cameras;
public:
 static TSharedRef<IDetailCustomization> MakeInstance(){return MakeShared<FCameraRefinementDetails>();}
 virtual void CustomizeDetails(IDetailLayoutBuilder& Builder) override {
  TArray<TWeakObjectPtr<UObject>> Objects; Builder.GetObjectsBeingCustomized(Objects);
  for(auto Object:Objects) {
   if(auto* Camera=Cast<UCameraComponent>(Object.Get())) Cameras.AddUnique(Camera);
   else if(auto* Actor=Cast<ACameraActor>(Object.Get())) Cameras.AddUnique(Actor->GetCameraComponent());
  }
  if(Cameras.IsEmpty()) return;
  Builder.EditCategory(TEXT("Camera Refinement"),FText::FromString(TEXT("相机细化")),ECategoryPriority::Important)
   .AddCustomRow(FText::FromString(TEXT("细化 Refinement")))
   .NameContent()[SNew(STextBlock).Text(FText::FromString(TEXT("细化")))]
   .ValueContent()[SNew(SHorizontalBox)
    +SHorizontalBox::Slot().AutoWidth()[SNew(SCheckBox)
    .ToolTipText_Lambda([](){return FText::FromString(TEXT("官方后处理体积自动按近裁剪平面分界；自定义材质通过 MF_RefinedCameraPosition 接入。\n")+GetDefault<UCameraRefinementSettings>()->NativeStatus);})
    .IsChecked_Lambda([this](){
     int32 Count=0;for(auto C:Cameras)Count+=UCameraRefinementLibrary::IsRefinementEnabled(C.Get())?1:0;
     return Count==0?ECheckBoxState::Unchecked:Count==Cameras.Num()?ECheckBoxState::Checked:ECheckBoxState::Undetermined;})
    .OnCheckStateChanged_Lambda([this](ECheckBoxState State){
     const FScopedTransaction Transaction(FText::FromString(TEXT("切换相机细化")));
     for(auto Camera:Cameras) UCameraRefinementLibrary::SetRefinementEnabled(Camera.Get(),State==ECheckBoxState::Checked);
    })]
    +SHorizontalBox::Slot().AutoWidth().Padding(8,0)[SNew(SButton).Text(FText::FromString(TEXT("跟随默认")))
     .OnClicked_Lambda([this](){
      const FScopedTransaction Transaction(FText::FromString(TEXT("相机跟随默认细化设置")));
      for(auto C:Cameras)if(C.IsValid()){C->Modify();C->RemoveUserDataOfClass(UCameraRefinementData::StaticClass());C->MarkPackageDirty();}
      return FReply::Handled();
     })]];
 }
};
class FCameraRefinementEditorModule : public IModuleInterface {
public:
 virtual void StartupModule() override {
  auto& Module=FModuleManager::LoadModuleChecked<FPropertyEditorModule>(TEXT("PropertyEditor"));
  for(const FName Name:{FName(TEXT("CameraComponent")),FName(TEXT("CameraActor"))})
   Module.RegisterCustomClassLayout(Name,FOnGetDetailCustomizationInstance::CreateStatic(&FCameraRefinementDetails::MakeInstance));
  Module.NotifyCustomizationModuleChanged();
  UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateLambda([](){
   FToolMenuOwnerScoped Owner(TEXT("CameraRefinement"));
   UToolMenu* Menu=UToolMenus::Get()->ExtendMenu(TEXT("LevelEditor.LevelEditorToolBar.PlayToolBar"));
   Menu->FindOrAddSection(TEXT("CameraRefinement")).AddEntry(FToolMenuEntry::InitWidget(TEXT("CameraRefinementDefault"),
    SNew(SCheckBox).ToolTipText_Lambda([](){const auto* S=GetDefault<UCameraRefinementSettings>();return FText::FromString(FString::Printf(TEXT("默认/未放置相机采用此设置；相机自己的显式设置优先。\n%s\n额外完整场景渲染：%d"),*S->NativeStatus,S->NativeExtraRenders));})
     .IsChecked_Lambda([](){return GetDefault<UCameraRefinementSettings>()->bDefaultEnabled?ECheckBoxState::Checked:ECheckBoxState::Unchecked;})
     .OnCheckStateChanged_Lambda([](ECheckBoxState State){auto* Settings=GetMutableDefault<UCameraRefinementSettings>();Settings->bDefaultEnabled=State==ECheckBoxState::Checked;Settings->SaveConfig();})
     [SNew(STextBlock).Text_Lambda([](){return FText::FromString(GetDefault<UCameraRefinementSettings>()->NativeStatus.StartsWith(TEXT("回退"))?TEXT("默认相机细化（原生回退）"):TEXT("默认相机细化"));})],FText::FromString(TEXT("默认相机细化"))));
  }));
 }
 virtual void ShutdownModule() override {
  UToolMenus::UnRegisterStartupCallback(this);
  UToolMenus::UnregisterOwner(TEXT("CameraRefinement"));
  if(auto* Module=FModuleManager::GetModulePtr<FPropertyEditorModule>(TEXT("PropertyEditor"))) {
   Module->UnregisterCustomClassLayout(TEXT("CameraComponent")); Module->UnregisterCustomClassLayout(TEXT("CameraActor"));
   Module->NotifyCustomizationModuleChanged();
  }
 }
};
IMPLEMENT_MODULE(FCameraRefinementEditorModule,CameraRefinementEditor)
extern "C" CAMERAREFINEMENTEDITOR_API const TCHAR* CameraRefinementEditorAuthor(){return TEXT("南京大学24届沈逸文");}
