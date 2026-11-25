// 作者：南京大学24届沈逸文
#pragma once
#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "CameraRefinementSettings.generated.h"
/** Fallback for free editor viewports, default player cameras, and cameras without local data. */
UCLASS(Config=Game,DefaultConfig,meta=(DisplayName="Camera Refinement / 相机细化"))
class CAMERAREFINEMENT_API UCameraRefinementSettings : public UDeveloperSettings {
 GENERATED_BODY()
public:
 UPROPERTY(Config,EditAnywhere,Category="Default Camera",meta=(DisplayName="默认相机细化"))
 bool bDefaultEnabled=false;
 UPROPERTY(Config,EditAnywhere,Category="Native Post Process",meta=(DisplayName="官方后处理体积细化"))
 bool bNativeVolumes=true;
 UPROPERTY(Config,EditAnywhere,Category="Native Post Process",meta=(ClampMin="2",ClampMax="8",DisplayName="最大原生渲染配置数"))
 int32 MaxNativeProfiles=8;
 UPROPERTY(VisibleAnywhere,Transient,Category="Native Post Process",meta=(DisplayName="最近视图状态"))
 FString NativeStatus;
 UPROPERTY(VisibleAnywhere,Transient,Category="Native Post Process",meta=(DisplayName="最近额外场景渲染数"))
 int32 NativeExtraRenders=0;
 virtual FName GetCategoryName() const override {return TEXT("Plugins");}
};
