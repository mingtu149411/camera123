// 作者：南京大学24届沈逸文
#pragma once
#include "CoreMinimal.h"
#include "Engine/AssetUserData.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "CameraRefinementData.generated.h"
class UCameraComponent;

/** Stored on any existing camera, including Blueprint/CineCamera subclasses. */
UCLASS(BlueprintType, EditInlineNew)
class CAMERAREFINEMENT_API UCameraRefinementData : public UAssetUserData {
 GENERATED_BODY()
public:
 UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Camera Refinement", meta=(DisplayName="细化"))
 bool bEnabled = false;
};

UCLASS()
class CAMERAREFINEMENT_API UCameraRefinementLibrary : public UBlueprintFunctionLibrary {
 GENERATED_BODY()
public:
 UFUNCTION(BlueprintPure, Category="Camera Refinement")
 static bool IsRefinementEnabled(UCameraComponent* Camera);
 UFUNCTION(BlueprintCallable, Category="Camera Refinement")
 static void SetRefinementEnabled(UCameraComponent* Camera, bool bEnabled);
};

/** Double precision CPU data, camera-relative to retain large-world precision. */
struct CAMERAREFINEMENT_API FCameraRefinementFrame {
 FVector Origin = FVector::ZeroVector;
 FVector Dx = FVector::ZeroVector;
 FVector Dy = FVector::ZeroVector;
 static FCameraRefinementFrame FromMatrices(const FMatrix& Projection, const FMatrix& ViewRotationToWorld);
 FVector At(const FVector2D& UV) const { return Origin + UV.X * Dx + UV.Y * Dy; }
};
