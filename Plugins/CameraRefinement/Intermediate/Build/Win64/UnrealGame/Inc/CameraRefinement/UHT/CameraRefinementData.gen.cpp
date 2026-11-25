// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CameraRefinementData.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeCameraRefinementData() {}

// ********** Begin Cross Module References ********************************************************
CAMERAREFINEMENT_API UClass* Z_Construct_UClass_UCameraRefinementData();
CAMERAREFINEMENT_API UClass* Z_Construct_UClass_UCameraRefinementData_NoRegister();
CAMERAREFINEMENT_API UClass* Z_Construct_UClass_UCameraRefinementLibrary();
CAMERAREFINEMENT_API UClass* Z_Construct_UClass_UCameraRefinementLibrary_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UAssetUserData();
ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
UPackage* Z_Construct_UPackage__Script_CameraRefinement();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UCameraRefinementData ****************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UCameraRefinementData;
UClass* UCameraRefinementData::GetPrivateStaticClass()
{
	using TClass = UCameraRefinementData;
	if (!Z_Registration_Info_UClass_UCameraRefinementData.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("CameraRefinementData"),
			Z_Registration_Info_UClass_UCameraRefinementData.InnerSingleton,
			StaticRegisterNativesUCameraRefinementData,
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
	return Z_Registration_Info_UClass_UCameraRefinementData.InnerSingleton;
}
UClass* Z_Construct_UClass_UCameraRefinementData_NoRegister()
{
	return UCameraRefinementData::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UCameraRefinementData_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/** Stored on any existing camera, including Blueprint/CineCamera subclasses. */" },
		{ "IncludePath", "CameraRefinementData.h" },
		{ "ModuleRelativePath", "Public/CameraRefinementData.h" },
		{ "ToolTip", "Stored on any existing camera, including Blueprint/CineCamera subclasses." },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bEnabled_MetaData[] = {
		{ "Category", "Camera Refinement" },
		{ "DisplayName", "\xe7\xbb\x86\xe5\x8c\x96" },
		{ "ModuleRelativePath", "Public/CameraRefinementData.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UCameraRefinementData constinit property declarations ********************
	static void NewProp_bEnabled_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnabled;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UCameraRefinementData constinit property declarations **********************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCameraRefinementData>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UCameraRefinementData_Statics

// ********** Begin Class UCameraRefinementData Property Definitions *******************************
void Z_Construct_UClass_UCameraRefinementData_Statics::NewProp_bEnabled_SetBit(void* Obj)
{
	((UCameraRefinementData*)Obj)->bEnabled = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UCameraRefinementData_Statics::NewProp_bEnabled = { "bEnabled", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UCameraRefinementData), &Z_Construct_UClass_UCameraRefinementData_Statics::NewProp_bEnabled_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bEnabled_MetaData), NewProp_bEnabled_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCameraRefinementData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCameraRefinementData_Statics::NewProp_bEnabled,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCameraRefinementData_Statics::PropPointers) < 2048);
// ********** End Class UCameraRefinementData Property Definitions *********************************
UObject* (*const Z_Construct_UClass_UCameraRefinementData_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UAssetUserData,
	(UObject* (*)())Z_Construct_UPackage__Script_CameraRefinement,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCameraRefinementData_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCameraRefinementData_Statics::ClassParams = {
	&UCameraRefinementData::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UCameraRefinementData_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UCameraRefinementData_Statics::PropPointers),
	0,
	0x003010A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCameraRefinementData_Statics::Class_MetaDataParams), Z_Construct_UClass_UCameraRefinementData_Statics::Class_MetaDataParams)
};
void UCameraRefinementData::StaticRegisterNativesUCameraRefinementData()
{
}
UClass* Z_Construct_UClass_UCameraRefinementData()
{
	if (!Z_Registration_Info_UClass_UCameraRefinementData.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCameraRefinementData.OuterSingleton, Z_Construct_UClass_UCameraRefinementData_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCameraRefinementData.OuterSingleton;
}
UCameraRefinementData::UCameraRefinementData(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UCameraRefinementData);
UCameraRefinementData::~UCameraRefinementData() {}
// ********** End Class UCameraRefinementData ******************************************************

// ********** Begin Class UCameraRefinementLibrary Function IsRefinementEnabled ********************
struct Z_Construct_UFunction_UCameraRefinementLibrary_IsRefinementEnabled_Statics
{
	struct CameraRefinementLibrary_eventIsRefinementEnabled_Parms
	{
		UCameraComponent* Camera;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Camera Refinement" },
		{ "ModuleRelativePath", "Public/CameraRefinementData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Camera_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA

// ********** Begin Function IsRefinementEnabled constinit property declarations *******************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Camera;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function IsRefinementEnabled constinit property declarations *********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function IsRefinementEnabled Property Definitions ******************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCameraRefinementLibrary_IsRefinementEnabled_Statics::NewProp_Camera = { "Camera", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CameraRefinementLibrary_eventIsRefinementEnabled_Parms, Camera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Camera_MetaData), NewProp_Camera_MetaData) };
void Z_Construct_UFunction_UCameraRefinementLibrary_IsRefinementEnabled_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((CameraRefinementLibrary_eventIsRefinementEnabled_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCameraRefinementLibrary_IsRefinementEnabled_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(CameraRefinementLibrary_eventIsRefinementEnabled_Parms), &Z_Construct_UFunction_UCameraRefinementLibrary_IsRefinementEnabled_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCameraRefinementLibrary_IsRefinementEnabled_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCameraRefinementLibrary_IsRefinementEnabled_Statics::NewProp_Camera,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCameraRefinementLibrary_IsRefinementEnabled_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCameraRefinementLibrary_IsRefinementEnabled_Statics::PropPointers) < 2048);
// ********** End Function IsRefinementEnabled Property Definitions ********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCameraRefinementLibrary_IsRefinementEnabled_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCameraRefinementLibrary, nullptr, "IsRefinementEnabled", 	Z_Construct_UFunction_UCameraRefinementLibrary_IsRefinementEnabled_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCameraRefinementLibrary_IsRefinementEnabled_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCameraRefinementLibrary_IsRefinementEnabled_Statics::CameraRefinementLibrary_eventIsRefinementEnabled_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCameraRefinementLibrary_IsRefinementEnabled_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCameraRefinementLibrary_IsRefinementEnabled_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCameraRefinementLibrary_IsRefinementEnabled_Statics::CameraRefinementLibrary_eventIsRefinementEnabled_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCameraRefinementLibrary_IsRefinementEnabled()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCameraRefinementLibrary_IsRefinementEnabled_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCameraRefinementLibrary::execIsRefinementEnabled)
{
	P_GET_OBJECT(UCameraComponent,Z_Param_Camera);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=UCameraRefinementLibrary::IsRefinementEnabled(Z_Param_Camera);
	P_NATIVE_END;
}
// ********** End Class UCameraRefinementLibrary Function IsRefinementEnabled **********************

// ********** Begin Class UCameraRefinementLibrary Function SetRefinementEnabled *******************
struct Z_Construct_UFunction_UCameraRefinementLibrary_SetRefinementEnabled_Statics
{
	struct CameraRefinementLibrary_eventSetRefinementEnabled_Parms
	{
		UCameraComponent* Camera;
		bool bEnabled;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "Camera Refinement" },
		{ "ModuleRelativePath", "Public/CameraRefinementData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Camera_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetRefinementEnabled constinit property declarations ******************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_Camera;
	static void NewProp_bEnabled_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bEnabled;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetRefinementEnabled constinit property declarations ********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetRefinementEnabled Property Definitions *****************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCameraRefinementLibrary_SetRefinementEnabled_Statics::NewProp_Camera = { "Camera", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CameraRefinementLibrary_eventSetRefinementEnabled_Parms, Camera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Camera_MetaData), NewProp_Camera_MetaData) };
void Z_Construct_UFunction_UCameraRefinementLibrary_SetRefinementEnabled_Statics::NewProp_bEnabled_SetBit(void* Obj)
{
	((CameraRefinementLibrary_eventSetRefinementEnabled_Parms*)Obj)->bEnabled = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCameraRefinementLibrary_SetRefinementEnabled_Statics::NewProp_bEnabled = { "bEnabled", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(CameraRefinementLibrary_eventSetRefinementEnabled_Parms), &Z_Construct_UFunction_UCameraRefinementLibrary_SetRefinementEnabled_Statics::NewProp_bEnabled_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCameraRefinementLibrary_SetRefinementEnabled_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCameraRefinementLibrary_SetRefinementEnabled_Statics::NewProp_Camera,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCameraRefinementLibrary_SetRefinementEnabled_Statics::NewProp_bEnabled,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCameraRefinementLibrary_SetRefinementEnabled_Statics::PropPointers) < 2048);
// ********** End Function SetRefinementEnabled Property Definitions *******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCameraRefinementLibrary_SetRefinementEnabled_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCameraRefinementLibrary, nullptr, "SetRefinementEnabled", 	Z_Construct_UFunction_UCameraRefinementLibrary_SetRefinementEnabled_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCameraRefinementLibrary_SetRefinementEnabled_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCameraRefinementLibrary_SetRefinementEnabled_Statics::CameraRefinementLibrary_eventSetRefinementEnabled_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCameraRefinementLibrary_SetRefinementEnabled_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCameraRefinementLibrary_SetRefinementEnabled_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCameraRefinementLibrary_SetRefinementEnabled_Statics::CameraRefinementLibrary_eventSetRefinementEnabled_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCameraRefinementLibrary_SetRefinementEnabled()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCameraRefinementLibrary_SetRefinementEnabled_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCameraRefinementLibrary::execSetRefinementEnabled)
{
	P_GET_OBJECT(UCameraComponent,Z_Param_Camera);
	P_GET_UBOOL(Z_Param_bEnabled);
	P_FINISH;
	P_NATIVE_BEGIN;
	UCameraRefinementLibrary::SetRefinementEnabled(Z_Param_Camera,Z_Param_bEnabled);
	P_NATIVE_END;
}
// ********** End Class UCameraRefinementLibrary Function SetRefinementEnabled *********************

// ********** Begin Class UCameraRefinementLibrary *************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UCameraRefinementLibrary;
UClass* UCameraRefinementLibrary::GetPrivateStaticClass()
{
	using TClass = UCameraRefinementLibrary;
	if (!Z_Registration_Info_UClass_UCameraRefinementLibrary.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("CameraRefinementLibrary"),
			Z_Registration_Info_UClass_UCameraRefinementLibrary.InnerSingleton,
			StaticRegisterNativesUCameraRefinementLibrary,
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
	return Z_Registration_Info_UClass_UCameraRefinementLibrary.InnerSingleton;
}
UClass* Z_Construct_UClass_UCameraRefinementLibrary_NoRegister()
{
	return UCameraRefinementLibrary::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UCameraRefinementLibrary_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "CameraRefinementData.h" },
		{ "ModuleRelativePath", "Public/CameraRefinementData.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UCameraRefinementLibrary constinit property declarations *****************
// ********** End Class UCameraRefinementLibrary constinit property declarations *******************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("IsRefinementEnabled"), .Pointer = &UCameraRefinementLibrary::execIsRefinementEnabled },
		{ .NameUTF8 = UTF8TEXT("SetRefinementEnabled"), .Pointer = &UCameraRefinementLibrary::execSetRefinementEnabled },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UCameraRefinementLibrary_IsRefinementEnabled, "IsRefinementEnabled" }, // 4072906687
		{ &Z_Construct_UFunction_UCameraRefinementLibrary_SetRefinementEnabled, "SetRefinementEnabled" }, // 1536120683
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCameraRefinementLibrary>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UCameraRefinementLibrary_Statics
UObject* (*const Z_Construct_UClass_UCameraRefinementLibrary_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
	(UObject* (*)())Z_Construct_UPackage__Script_CameraRefinement,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCameraRefinementLibrary_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCameraRefinementLibrary_Statics::ClassParams = {
	&UCameraRefinementLibrary::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCameraRefinementLibrary_Statics::Class_MetaDataParams), Z_Construct_UClass_UCameraRefinementLibrary_Statics::Class_MetaDataParams)
};
void UCameraRefinementLibrary::StaticRegisterNativesUCameraRefinementLibrary()
{
	UClass* Class = UCameraRefinementLibrary::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UCameraRefinementLibrary_Statics::Funcs));
}
UClass* Z_Construct_UClass_UCameraRefinementLibrary()
{
	if (!Z_Registration_Info_UClass_UCameraRefinementLibrary.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCameraRefinementLibrary.OuterSingleton, Z_Construct_UClass_UCameraRefinementLibrary_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCameraRefinementLibrary.OuterSingleton;
}
UCameraRefinementLibrary::UCameraRefinementLibrary(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UCameraRefinementLibrary);
UCameraRefinementLibrary::~UCameraRefinementLibrary() {}
// ********** End Class UCameraRefinementLibrary ***************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_camera123_UE_Build_Production_HostProject_Plugins_CameraRefinement_Source_CameraRefinement_Public_CameraRefinementData_h__Script_CameraRefinement_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UCameraRefinementData, UCameraRefinementData::StaticClass, TEXT("UCameraRefinementData"), &Z_Registration_Info_UClass_UCameraRefinementData, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCameraRefinementData), 253105657U) },
		{ Z_Construct_UClass_UCameraRefinementLibrary, UCameraRefinementLibrary::StaticClass, TEXT("UCameraRefinementLibrary"), &Z_Registration_Info_UClass_UCameraRefinementLibrary, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCameraRefinementLibrary), 2149091586U) },
	};
}; // Z_CompiledInDeferFile_FID_camera123_UE_Build_Production_HostProject_Plugins_CameraRefinement_Source_CameraRefinement_Public_CameraRefinementData_h__Script_CameraRefinement_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_camera123_UE_Build_Production_HostProject_Plugins_CameraRefinement_Source_CameraRefinement_Public_CameraRefinementData_h__Script_CameraRefinement_1066786146{
	TEXT("/Script/CameraRefinement"),
	Z_CompiledInDeferFile_FID_camera123_UE_Build_Production_HostProject_Plugins_CameraRefinement_Source_CameraRefinement_Public_CameraRefinementData_h__Script_CameraRefinement_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_camera123_UE_Build_Production_HostProject_Plugins_CameraRefinement_Source_CameraRefinement_Public_CameraRefinementData_h__Script_CameraRefinement_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
