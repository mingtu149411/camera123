// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "CameraRefinementSettings.h"

#ifdef CAMERAREFINEMENT_CameraRefinementSettings_generated_h
#error "CameraRefinementSettings.generated.h already included, missing '#pragma once' in CameraRefinementSettings.h"
#endif
#define CAMERAREFINEMENT_CameraRefinementSettings_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

// ********** Begin Class UCameraRefinementSettings ************************************************
struct Z_Construct_UClass_UCameraRefinementSettings_Statics;
CAMERAREFINEMENT_API UClass* Z_Construct_UClass_UCameraRefinementSettings_NoRegister();

#define FID_camera123_UE_Build_Production_HostProject_Plugins_CameraRefinement_Source_CameraRefinement_Public_CameraRefinementSettings_h_9_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCameraRefinementSettings(); \
	friend struct ::Z_Construct_UClass_UCameraRefinementSettings_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend CAMERAREFINEMENT_API UClass* ::Z_Construct_UClass_UCameraRefinementSettings_NoRegister(); \
public: \
	DECLARE_CLASS2(UCameraRefinementSettings, UDeveloperSettings, COMPILED_IN_FLAGS(0 | CLASS_DefaultConfig | CLASS_Config), CASTCLASS_None, TEXT("/Script/CameraRefinement"), Z_Construct_UClass_UCameraRefinementSettings_NoRegister) \
	DECLARE_SERIALIZER(UCameraRefinementSettings) \
	static constexpr const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define FID_camera123_UE_Build_Production_HostProject_Plugins_CameraRefinement_Source_CameraRefinement_Public_CameraRefinementSettings_h_9_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UCameraRefinementSettings(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UCameraRefinementSettings(UCameraRefinementSettings&&) = delete; \
	UCameraRefinementSettings(const UCameraRefinementSettings&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCameraRefinementSettings); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCameraRefinementSettings); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCameraRefinementSettings) \
	NO_API virtual ~UCameraRefinementSettings();


#define FID_camera123_UE_Build_Production_HostProject_Plugins_CameraRefinement_Source_CameraRefinement_Public_CameraRefinementSettings_h_7_PROLOG
#define FID_camera123_UE_Build_Production_HostProject_Plugins_CameraRefinement_Source_CameraRefinement_Public_CameraRefinementSettings_h_9_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_camera123_UE_Build_Production_HostProject_Plugins_CameraRefinement_Source_CameraRefinement_Public_CameraRefinementSettings_h_9_INCLASS_NO_PURE_DECLS \
	FID_camera123_UE_Build_Production_HostProject_Plugins_CameraRefinement_Source_CameraRefinement_Public_CameraRefinementSettings_h_9_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UCameraRefinementSettings;

// ********** End Class UCameraRefinementSettings **************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_camera123_UE_Build_Production_HostProject_Plugins_CameraRefinement_Source_CameraRefinement_Public_CameraRefinementSettings_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
