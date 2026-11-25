// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CameraRefinementSettings.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeCameraRefinementSettings() {}

// ********** Begin Cross Module References ********************************************************
CAMERAREFINEMENT_API UClass* Z_Construct_UClass_UCameraRefinementSettings();
CAMERAREFINEMENT_API UClass* Z_Construct_UClass_UCameraRefinementSettings_NoRegister();
DEVELOPERSETTINGS_API UClass* Z_Construct_UClass_UDeveloperSettings();
UPackage* Z_Construct_UPackage__Script_CameraRefinement();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UCameraRefinementSettings ************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UCameraRefinementSettings;
UClass* UCameraRefinementSettings::GetPrivateStaticClass()
{
	using TClass = UCameraRefinementSettings;
	if (!Z_Registration_Info_UClass_UCameraRefinementSettings.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("CameraRefinementSettings"),
			Z_Registration_Info_UClass_UCameraRefinementSettings.InnerSingleton,
			StaticRegisterNativesUCameraRefinementSettings,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_UCameraRefinementSettings.InnerSingleton;
}
UClass* Z_Construct_UClass_UCameraRefinementSettings_NoRegister()
{
	return UCameraRefinementSettings::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UCameraRefinementSettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "Comment", "/** Fallback for free editor viewports, default player cameras, and cameras without local data. */" },
		{ "DisplayName", "Camera Refinement / \xe7\x9b\xb8\xe6\x9c\xba\xe7\xbb\x86\xe5\x8c\x96" },
		{ "IncludePath", "CameraRefinementSettings.h" },
		{ "ModuleRelativePath", "Public/CameraRefinementSettings.h" },
		{ "ToolTip", "Fallback for free editor viewports, default player cameras, and cameras without local data." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bDefaultEnabled_MetaData[] = {
		{ "Category", "Default Camera" },
		{ "DisplayName", "\xe9\xbb\x98\xe8\xae\xa4\xe7\x9b\xb8\xe6\x9c\xba\xe7\xbb\x86\xe5\x8c\x96" },
		{ "ModuleRelativePath", "Public/CameraRefinementSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bNativeVolumes_MetaData[] = {
		{ "Category", "Native Post Process" },
		{ "DisplayName", "\xe5\xae\x98\xe6\x96\xb9\xe5\x90\x8e\xe5\xa4\x84\xe7\x90\x86\xe4\xbd\x93\xe7\xa7\xaf\xe7\xbb\x86\xe5\x8c\x96" },
		{ "ModuleRelativePath", "Public/CameraRefinementSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MaxNativeProfiles_MetaData[] = {
		{ "Category", "Native Post Process" },
		{ "ClampMax", "8" },
		{ "ClampMin", "2" },
		{ "DisplayName", "\xe6\x9c\x80\xe5\xa4\xa7\xe5\x8e\x9f\xe7\x94\x9f\xe6\xb8\xb2\xe6\x9f\x93\xe9\x85\x8d\xe7\xbd\xae\xe6\x95\xb0" },
		{ "ModuleRelativePath", "Public/CameraRefinementSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NativeStatus_MetaData[] = {
		{ "Category", "Native Post Process" },
		{ "DisplayName", "\xe6\x9c\x80\xe8\xbf\x91\xe8\xa7\x86\xe5\x9b\xbe\xe7\x8a\xb6\xe6\x80\x81" },
		{ "ModuleRelativePath", "Public/CameraRefinementSettings.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NativeExtraRenders_MetaData[] = {
		{ "Category", "Native Post Process" },
		{ "DisplayName", "\xe6\x9c\x80\xe8\xbf\x91\xe9\xa2\x9d\xe5\xa4\x96\xe5\x9c\xba\xe6\x99\xaf\xe6\xb8\xb2\xe6\x9f\x93\xe6\x95\xb0" },
		{ "ModuleRelativePath", "Public/CameraRefinementSettings.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UCameraRefinementSettings constinit property declarations ****************
	static void NewProp_bDefaultEnabled_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bDefaultEnabled;
	static void NewProp_bNativeVolumes_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bNativeVolumes;
	static const UECodeGen_Private::FIntPropertyParams NewProp_MaxNativeProfiles;
	static const UECodeGen_Private::FStrPropertyParams NewProp_NativeStatus;
	static const UECodeGen_Private::FIntPropertyParams NewProp_NativeExtraRenders;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UCameraRefinementSettings constinit property declarations ******************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCameraRefinementSettings>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UCameraRefinementSettings_Statics

// ********** Begin Class UCameraRefinementSettings Property Definitions ***************************
void Z_Construct_UClass_UCameraRefinementSettings_Statics::NewProp_bDefaultEnabled_SetBit(void* Obj)
{
	((UCameraRefinementSettings*)Obj)->bDefaultEnabled = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UCameraRefinementSettings_Statics::NewProp_bDefaultEnabled = { "bDefaultEnabled", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UCameraRefinementSettings), &Z_Construct_UClass_UCameraRefinementSettings_Statics::NewProp_bDefaultEnabled_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bDefaultEnabled_MetaData), NewProp_bDefaultEnabled_MetaData) };
void Z_Construct_UClass_UCameraRefinementSettings_Statics::NewProp_bNativeVolumes_SetBit(void* Obj)
{
	((UCameraRefinementSettings*)Obj)->bNativeVolumes = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UCameraRefinementSettings_Statics::NewProp_bNativeVolumes = { "bNativeVolumes", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UCameraRefinementSettings), &Z_Construct_UClass_UCameraRefinementSettings_Statics::NewProp_bNativeVolumes_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bNativeVolumes_MetaData), NewProp_bNativeVolumes_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UCameraRefinementSettings_Statics::NewProp_MaxNativeProfiles = { "MaxNativeProfiles", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCameraRefinementSettings, MaxNativeProfiles), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MaxNativeProfiles_MetaData), NewProp_MaxNativeProfiles_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UCameraRefinementSettings_Statics::NewProp_NativeStatus = { "NativeStatus", nullptr, (EPropertyFlags)0x0010000000022001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCameraRefinementSettings, NativeStatus), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NativeStatus_MetaData), NewProp_NativeStatus_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UCameraRefinementSettings_Statics::NewProp_NativeExtraRenders = { "NativeExtraRenders", nullptr, (EPropertyFlags)0x0010000000022001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCameraRefinementSettings, NativeExtraRenders), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NativeExtraRenders_MetaData), NewProp_NativeExtraRenders_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCameraRefinementSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCameraRefinementSettings_Statics::NewProp_bDefaultEnabled,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCameraRefinementSettings_Statics::NewProp_bNativeVolumes,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCameraRefinementSettings_Statics::NewProp_MaxNativeProfiles,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCameraRefinementSettings_Statics::NewProp_NativeStatus,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCameraRefinementSettings_Statics::NewProp_NativeExtraRenders,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCameraRefinementSettings_Statics::PropPointers) < 2048);
// ********** End Class UCameraRefinementSettings Property Definitions *****************************
UObject* (*const Z_Construct_UClass_UCameraRefinementSettings_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UDeveloperSettings,
	(UObject* (*)())Z_Construct_UPackage__Script_CameraRefinement,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCameraRefinementSettings_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCameraRefinementSettings_Statics::ClassParams = {
	&UCameraRefinementSettings::StaticClass,
	"Game",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UCameraRefinementSettings_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UCameraRefinementSettings_Statics::PropPointers),
	0,
	0x001000A6u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCameraRefinementSettings_Statics::Class_MetaDataParams), Z_Construct_UClass_UCameraRefinementSettings_Statics::Class_MetaDataParams)
};
void UCameraRefinementSettings::StaticRegisterNativesUCameraRefinementSettings()
{
}
UClass* Z_Construct_UClass_UCameraRefinementSettings()
{
	if (!Z_Registration_Info_UClass_UCameraRefinementSettings.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCameraRefinementSettings.OuterSingleton, Z_Construct_UClass_UCameraRefinementSettings_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCameraRefinementSettings.OuterSingleton;
}
UCameraRefinementSettings::UCameraRefinementSettings(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UCameraRefinementSettings);
UCameraRefinementSettings::~UCameraRefinementSettings() {}
// ********** End Class UCameraRefinementSettings **************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_camera123_UE_Build_Production_HostProject_Plugins_CameraRefinement_Source_CameraRefinement_Public_CameraRefinementSettings_h__Script_CameraRefinement_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UCameraRefinementSettings, UCameraRefinementSettings::StaticClass, TEXT("UCameraRefinementSettings"), &Z_Registration_Info_UClass_UCameraRefinementSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCameraRefinementSettings), 3338247054U) },
	};
}; // Z_CompiledInDeferFile_FID_camera123_UE_Build_Production_HostProject_Plugins_CameraRefinement_Source_CameraRefinement_Public_CameraRefinementSettings_h__Script_CameraRefinement_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_camera123_UE_Build_Production_HostProject_Plugins_CameraRefinement_Source_CameraRefinement_Public_CameraRefinementSettings_h__Script_CameraRefinement_2122682913{
	TEXT("/Script/CameraRefinement"),
	Z_CompiledInDeferFile_FID_camera123_UE_Build_Production_HostProject_Plugins_CameraRefinement_Source_CameraRefinement_Public_CameraRefinementSettings_h__Script_CameraRefinement_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_camera123_UE_Build_Production_HostProject_Plugins_CameraRefinement_Source_CameraRefinement_Public_CameraRefinementSettings_h__Script_CameraRefinement_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
