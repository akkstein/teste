// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VivoxCore/Public/Presence.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePresence() {}
// Cross Module References
	VIVOXCORE_API UEnum* Z_Construct_UEnum_VivoxCore_PresenceStatus();
	UPackage* Z_Construct_UPackage__Script_VivoxCore();
// End Cross Module References
	static UEnum* PresenceStatus_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_VivoxCore_PresenceStatus, Z_Construct_UPackage__Script_VivoxCore(), TEXT("PresenceStatus"));
		}
		return Singleton;
	}
	template<> VIVOXCORE_API UEnum* StaticEnum<PresenceStatus>()
	{
		return PresenceStatus_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_PresenceStatus(PresenceStatus_StaticEnum, TEXT("/Script/VivoxCore"), TEXT("PresenceStatus"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_VivoxCore_PresenceStatus_Hash() { return 3608538538U; }
	UEnum* Z_Construct_UEnum_VivoxCore_PresenceStatus()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_VivoxCore();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("PresenceStatus"), 0, Get_Z_Construct_UEnum_VivoxCore_PresenceStatus_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "PresenceStatus::Unavailable", (int64)PresenceStatus::Unavailable },
				{ "PresenceStatus::Available", (int64)PresenceStatus::Available },
				{ "PresenceStatus::Chat", (int64)PresenceStatus::Chat },
				{ "PresenceStatus::DoNotDisturb", (int64)PresenceStatus::DoNotDisturb },
				{ "PresenceStatus::Away", (int64)PresenceStatus::Away },
				{ "PresenceStatus::ExtendedAway", (int64)PresenceStatus::ExtendedAway },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "Available.Comment", "/**\n    * \\brief Generally available\n    */" },
				{ "Available.Name", "PresenceStatus::Available" },
				{ "Available.ToolTip", "\\brief Generally available" },
				{ "Away.Comment", "/**\n    * \\brief Away\n    */" },
				{ "Away.Name", "PresenceStatus::Away" },
				{ "Away.ToolTip", "\\brief Away" },
				{ "BlueprintType", "true" },
				{ "Chat.Comment", "/**\n    * \\brief Available to chat\n    */" },
				{ "Chat.Name", "PresenceStatus::Chat" },
				{ "Chat.ToolTip", "\\brief Available to chat" },
				{ "Comment", "/**\n* \\brief The online status of the user. Note that these must be equivalent to Vivox Native SDK vx_buddy_presence_state values.\n*/" },
				{ "DoNotDisturb.Comment", "/**\n    * \\brief Do Not Disturb\n    */" },
				{ "DoNotDisturb.Name", "PresenceStatus::DoNotDisturb" },
				{ "DoNotDisturb.ToolTip", "\\brief Do Not Disturb" },
				{ "ExtendedAway.Comment", "/**\n    * \\brief Away for an extended period of time.\n    */" },
				{ "ExtendedAway.Name", "PresenceStatus::ExtendedAway" },
				{ "ExtendedAway.ToolTip", "\\brief Away for an extended period of time." },
				{ "ModuleRelativePath", "Public/Presence.h" },
				{ "ToolTip", "\\brief The online status of the user. Note that these must be equivalent to Vivox Native SDK vx_buddy_presence_state values." },
				{ "Unavailable.Comment", "/**\n    * \\brief Not available (offline)\n    */" },
				{ "Unavailable.Name", "PresenceStatus::Unavailable" },
				{ "Unavailable.ToolTip", "\\brief Not available (offline)" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_VivoxCore,
				nullptr,
				"PresenceStatus",
				"PresenceStatus",
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
