// 作者：南京大学24届沈逸文
#pragma once
#include "CoreMinimal.h"
#include "SceneViewExtension.h"
class FCameraRefinementViewExtension;
TSharedPtr<FCameraRefinementViewExtension,ESPMode::ThreadSafe> MakeCameraRefinementExtension();
void ReleaseCameraRefinementWorld(const TSharedPtr<FCameraRefinementViewExtension,ESPMode::ThreadSafe>& Extension,UWorld* World);
void ShutdownCameraRefinement(const TSharedPtr<FCameraRefinementViewExtension,ESPMode::ThreadSafe>& Extension);
