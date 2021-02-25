// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VivoxCore/Public/ConnectionState.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeConnectionState() {}
// Cross Module References
	VIVOXCORE_API UEnum* Z_Construct_UEnum_VivoxCore_ConnectionState();
	UPackage* Z_Construct_UPackage__Script_VivoxCore();
// End Cross Module References
	static UEnum* ConnectionState_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_VivoxCore_ConnectionState, Z_Construct_UPackage__Script_VivoxCore(), TEXT("ConnectionState"));
		}
		return Singleton;
	}
	template<> VIVOXCORE_API UEnum* StaticEnum<ConnectionState>()
	{
		return ConnectionState_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_ConnectionState(ConnectionState_StaticEnum, TEXT("/Script/VivoxCore"), TEXT("ConnectionState"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_VivoxCore_ConnectionState_Hash() { return 3763461533U; }
	UEnum* Z_Construct_UEnum_VivoxCore_ConnectionState()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_VivoxCore();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("ConnectionState"), 0, Get_Z_Construct_UEnum_VivoxCore_ConnectionState_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "ConnectionState::Disconnected", (int64)ConnectionState::Disconnected },
				{ "ConnectionState::Connecting", (int64)ConnectionState::Connecting },
				{ "ConnectionState::Connected", (int64)ConnectionState::Connected },
				{ "ConnectionState::Disconnecting", (int64)ConnectionState::Disconnecting },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "Comment", "/**\n * \\brief Represents the state of any resource with connection semantics\n */" },
				{ "Connected.Comment", "/**\n     * \\brief The resource is connected\n     */" },
				{ "Connected.Name", "ConnectionState::Connected" },
				{ "Connected.ToolTip", "\\brief The resource is connected" },
				{ "Connecting.Comment", "/**\n     * \\brief The resource is in the process of connecting\n     */" },
				{ "Connecting.Name", "ConnectionState::Connecting" },
				{ "Connecting.ToolTip", "\\brief The resource is in the process of connecting" },
				{ "Disconnected.Comment", "/**\n     *\\brief The resource is disconnected\n     */" },
				{ "Disconnected.Name", "ConnectionState::Disconnected" },
				{ "Disconnected.ToolTip", "\\brief The resource is disconnected" },
				{ "Disconnecting.Comment", "/**\n     * \\brief The resource is in the process of disconnecting\n     */" },
				{ "Disconnecting.Name", "ConnectionState::Disconnecting" },
				{ "Disconnecting.ToolTip", "\\brief The resource is in the process of disconnecting" },
				{ "ModuleRelativePath", "Public/ConnectionState.h" },
				{ "ToolTip", "\\brief Represents the state of any resource with connection semantics" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_VivoxCore,
				nullptr,
				"ConnectionState",
				"ConnectionState",
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
