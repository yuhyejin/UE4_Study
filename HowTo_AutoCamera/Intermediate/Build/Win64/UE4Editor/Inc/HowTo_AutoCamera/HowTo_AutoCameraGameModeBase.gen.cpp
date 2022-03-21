// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "HowTo_AutoCamera/HowTo_AutoCameraGameModeBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeHowTo_AutoCameraGameModeBase() {}
// Cross Module References
	HOWTO_AUTOCAMERA_API UClass* Z_Construct_UClass_AHowTo_AutoCameraGameModeBase_NoRegister();
	HOWTO_AUTOCAMERA_API UClass* Z_Construct_UClass_AHowTo_AutoCameraGameModeBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_HowTo_AutoCamera();
// End Cross Module References
	void AHowTo_AutoCameraGameModeBase::StaticRegisterNativesAHowTo_AutoCameraGameModeBase()
	{
	}
	UClass* Z_Construct_UClass_AHowTo_AutoCameraGameModeBase_NoRegister()
	{
		return AHowTo_AutoCameraGameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_AHowTo_AutoCameraGameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AHowTo_AutoCameraGameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_HowTo_AutoCamera,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AHowTo_AutoCameraGameModeBase_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "HowTo_AutoCameraGameModeBase.h" },
		{ "ModuleRelativePath", "HowTo_AutoCameraGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AHowTo_AutoCameraGameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AHowTo_AutoCameraGameModeBase>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AHowTo_AutoCameraGameModeBase_Statics::ClassParams = {
		&AHowTo_AutoCameraGameModeBase::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_AHowTo_AutoCameraGameModeBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AHowTo_AutoCameraGameModeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AHowTo_AutoCameraGameModeBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AHowTo_AutoCameraGameModeBase_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AHowTo_AutoCameraGameModeBase, 2181166598);
	template<> HOWTO_AUTOCAMERA_API UClass* StaticClass<AHowTo_AutoCameraGameModeBase>()
	{
		return AHowTo_AutoCameraGameModeBase::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AHowTo_AutoCameraGameModeBase(Z_Construct_UClass_AHowTo_AutoCameraGameModeBase, &AHowTo_AutoCameraGameModeBase::StaticClass, TEXT("/Script/HowTo_AutoCamera"), TEXT("AHowTo_AutoCameraGameModeBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AHowTo_AutoCameraGameModeBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
