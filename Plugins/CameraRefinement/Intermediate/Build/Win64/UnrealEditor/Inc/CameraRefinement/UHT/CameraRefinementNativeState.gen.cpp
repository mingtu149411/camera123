// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CameraRefinementNativeState.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeCameraRefinementNativeState() {}

// ********** Begin Cross Module References ********************************************************
CAMERAREFINEMENT_API UClass* Z_Construct_UClass_UCameraRefinementNativeState();
CAMERAREFINEMENT_API UClass* Z_Construct_UClass_UCameraRefinementNativeState_NoRegister();
COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
ENGINE_API UClass* Z_Construct_UClass_USceneCaptureComponent2D_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UTextureRenderTarget2D_NoRegister();
UPackage* Z_Construct_UPackage__Script_CameraRefinement();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UCameraRefinementNativeState *********************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UCameraRefinementNativeState;
UClass* UCameraRefinementNativeState::GetPrivateStaticClass()
{
	using TClass = UCameraRefinementNativeState;
	if (!Z_Registration_Info_UClass_UCameraRefinementNativeState.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("CameraRefinementNativeState"),
			Z_Registration_Info_UClass_UCameraRefinementNativeState.InnerSingleton,
			StaticRegisterNativesUCameraRefinementNativeState,
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
	return Z_Registration_Info_UClass_UCameraRefinementNativeState.InnerSingleton;
}
UClass* Z_Construct_UClass_UCameraRefinementNativeState_NoRegister()
{
	return UCameraRefinementNativeState::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UCameraRefinementNativeState_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "Comment", "/** Transient camera render resources; never placed in a level or saved. */" },
		{ "IncludePath", "CameraRefinementNativeState.h" },
		{ "ModuleRelativePath", "Private/CameraRefinementNativeState.h" },
		{ "ToolTip", "Transient camera render resources; never placed in a level or saved." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Captures_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Private/CameraRefinementNativeState.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Targets_MetaData[] = {
		{ "ModuleRelativePath", "Private/CameraRefinementNativeState.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UCameraRefinementNativeState constinit property declarations *************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Captures_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Captures;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Targets_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Targets;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UCameraRefinementNativeState constinit property declarations ***************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCameraRefinementNativeState>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UCameraRefinementNativeState_Statics

// ********** Begin Class UCameraRefinementNativeState Property Definitions ************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UCameraRefinementNativeState_Statics::NewProp_Captures_Inner = { "Captures", nullptr, (EPropertyFlags)0x0104000000080008, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_USceneCaptureComponent2D_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UCameraRefinementNativeState_Statics::NewProp_Captures = { "Captures", nullptr, (EPropertyFlags)0x0114008000002008, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCameraRefinementNativeState, Captures), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Captures_MetaData), NewProp_Captures_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UCameraRefinementNativeState_Statics::NewProp_Targets_Inner = { "Targets", nullptr, (EPropertyFlags)0x0104000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UTextureRenderTarget2D_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UCameraRefinementNativeState_Statics::NewProp_Targets = { "Targets", nullptr, (EPropertyFlags)0x0114000000002000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCameraRefinementNativeState, Targets), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Targets_MetaData), NewProp_Targets_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCameraRefinementNativeState_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCameraRefinementNativeState_Statics::NewProp_Captures_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCameraRefinementNativeState_Statics::NewProp_Captures,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCameraRefinementNativeState_Statics::NewProp_Targets_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCameraRefinementNativeState_Statics::NewProp_Targets,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCameraRefinementNativeState_Statics::PropPointers) < 2048);
// ********** End Class UCameraRefinementNativeState Property Definitions **************************
UObject* (*const Z_Construct_UClass_UCameraRefinementNativeState_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UObject,
	(UObject* (*)())Z_Construct_UPackage__Script_CameraRefinement,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCameraRefinementNativeState_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCameraRefinementNativeState_Statics::ClassParams = {
	&UCameraRefinementNativeState::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UCameraRefinementNativeState_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UCameraRefinementNativeState_Statics::PropPointers),
	0,
	0x008000A8u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCameraRefinementNativeState_Statics::Class_MetaDataParams), Z_Construct_UClass_UCameraRefinementNativeState_Statics::Class_MetaDataParams)
};
void UCameraRefinementNativeState::StaticRegisterNativesUCameraRefinementNativeState()
{
}
UClass* Z_Construct_UClass_UCameraRefinementNativeState()
{
	if (!Z_Registration_Info_UClass_UCameraRefinementNativeState.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCameraRefinementNativeState.OuterSingleton, Z_Construct_UClass_UCameraRefinementNativeState_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCameraRefinementNativeState.OuterSingleton;
}
UCameraRefinementNativeState::UCameraRefinementNativeState(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UCameraRefinementNativeState);
UCameraRefinementNativeState::~UCameraRefinementNativeState() {}
// ********** End Class UCameraRefinementNativeState ***********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_camera123_UE_Build_Production_HostProject_Plugins_CameraRefinement_Source_CameraRefinement_Private_CameraRefinementNativeState_h__Script_CameraRefinement_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UCameraRefinementNativeState, UCameraRefinementNativeState::StaticClass, TEXT("UCameraRefinementNativeState"), &Z_Registration_Info_UClass_UCameraRefinementNativeState, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCameraRefinementNativeState), 3652346548U) },
	};
}; // Z_CompiledInDeferFile_FID_camera123_UE_Build_Production_HostProject_Plugins_CameraRefinement_Source_CameraRefinement_Private_CameraRefinementNativeState_h__Script_CameraRefinement_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_camera123_UE_Build_Production_HostProject_Plugins_CameraRefinement_Source_CameraRefinement_Private_CameraRefinementNativeState_h__Script_CameraRefinement_8770539{
	TEXT("/Script/CameraRefinement"),
	Z_CompiledInDeferFile_FID_camera123_UE_Build_Production_HostProject_Plugins_CameraRefinement_Source_CameraRefinement_Private_CameraRefinementNativeState_h__Script_CameraRefinement_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_camera123_UE_Build_Production_HostProject_Plugins_CameraRefinement_Source_CameraRefinement_Private_CameraRefinementNativeState_h__Script_CameraRefinement_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
