// 作者：南京大学24届沈逸文
#pragma once
#include "CoreMinimal.h"
#include "Components/SceneCaptureComponent2D.h"
#include "CameraRefinementNativeState.generated.h"
class UTextureRenderTarget2D;
/** Transient camera render resources; never placed in a level or saved. */
UCLASS(Transient)
class UCameraRefinementNativeState : public UObject {
 GENERATED_BODY()
public:
 UPROPERTY(Transient) TArray<TObjectPtr<USceneCaptureComponent2D>> Captures;
 UPROPERTY(Transient) TArray<TObjectPtr<UTextureRenderTarget2D>> Targets;
 TWeakObjectPtr<UWorld> World;
 virtual UWorld* GetWorld() const override {return World.Get();}
};
