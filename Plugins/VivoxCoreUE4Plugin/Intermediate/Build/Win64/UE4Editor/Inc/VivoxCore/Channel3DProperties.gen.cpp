// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VivoxCore/Public/Channel3DProperties.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeChannel3DProperties() {}
// Cross Module References
	VIVOXCORE_API UEnum* Z_Construct_UEnum_VivoxCore_EAudioFadeModel();
	UPackage* Z_Construct_UPackage__Script_VivoxCore();
// End Cross Module References
	static UEnum* EAudioFadeModel_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_VivoxCore_EAudioFadeModel, Z_Construct_UPackage__Script_VivoxCore(), TEXT("EAudioFadeModel"));
		}
		return Singleton;
	}
	template<> VIVOXCORE_API UEnum* StaticEnum<EAudioFadeModel>()
	{
		return EAudioFadeModel_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EAudioFadeModel(EAudioFadeModel_StaticEnum, TEXT("/Script/VivoxCore"), TEXT("EAudioFadeModel"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_VivoxCore_EAudioFadeModel_Hash() { return 3242952714U; }
	UEnum* Z_Construct_UEnum_VivoxCore_EAudioFadeModel()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_VivoxCore();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EAudioFadeModel"), 0, Get_Z_Construct_UEnum_VivoxCore_EAudioFadeModel_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EAudioFadeModel::InverseByDistance", (int64)EAudioFadeModel::InverseByDistance },
				{ "EAudioFadeModel::LinearByDistance", (int64)EAudioFadeModel::LinearByDistance },
				{ "EAudioFadeModel::ExponentialByDistance", (int64)EAudioFadeModel::ExponentialByDistance },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "Comment", "/**\n  * \\brief The distance model for a Positional channel, which determines the algorithm to use when computing attenuation\n  */" },
				{ "ExponentialByDistance.Comment", "/**\n     * \\brief Makes voice within the conversational distance louder, but fade quickly beyond it.\n     */" },
				{ "ExponentialByDistance.Name", "EAudioFadeModel::ExponentialByDistance" },
				{ "ExponentialByDistance.ToolTip", "\\brief Makes voice within the conversational distance louder, but fade quickly beyond it." },
				{ "InverseByDistance.Comment", "/**\n     * \\brief Fades voice quickly at first, buts slows down as you get further from conversational distance.\n     */" },
				{ "InverseByDistance.Name", "EAudioFadeModel::InverseByDistance" },
				{ "InverseByDistance.ToolTip", "\\brief Fades voice quickly at first, buts slows down as you get further from conversational distance." },
				{ "LinearByDistance.Comment", "/**\n     * \\brief Fades voice slowly at first, but speeds up as you get further from conversational distance.\n     */" },
				{ "LinearByDistance.Name", "EAudioFadeModel::LinearByDistance" },
				{ "LinearByDistance.ToolTip", "\\brief Fades voice slowly at first, but speeds up as you get further from conversational distance." },
				{ "ModuleRelativePath", "Public/Channel3DProperties.h" },
				{ "ToolTip", "\\brief The distance model for a Positional channel, which determines the algorithm to use when computing attenuation" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_VivoxCore,
				nullptr,
				"EAudioFadeModel",
				"EAudioFadeModel",
				Enumerators,
				UE_ARRAY_COUNT(Enumerators),
				RF_Public|RF_Transient|RF_MarkAsNative,
				EEnumFlags::None,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				(uint8)UEnum::ECppForm::EnumClass,
				METADATA_PARAMS(Enum_MetaDataParams, UE_ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
