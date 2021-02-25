// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VivoxCore/Public/ITTSMessage.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeITTSMessage() {}
// Cross Module References
	VIVOXCORE_API UEnum* Z_Construct_UEnum_VivoxCore_TTSMessageState();
	UPackage* Z_Construct_UPackage__Script_VivoxCore();
	VIVOXCORE_API UEnum* Z_Construct_UEnum_VivoxCore_TTSDestination();
// End Cross Module References
	static UEnum* TTSMessageState_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_VivoxCore_TTSMessageState, Z_Construct_UPackage__Script_VivoxCore(), TEXT("TTSMessageState"));
		}
		return Singleton;
	}
	template<> VIVOXCORE_API UEnum* StaticEnum<TTSMessageState>()
	{
		return TTSMessageState_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_TTSMessageState(TTSMessageState_StaticEnum, TEXT("/Script/VivoxCore"), TEXT("TTSMessageState"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_VivoxCore_TTSMessageState_Hash() { return 156063656U; }
	UEnum* Z_Construct_UEnum_VivoxCore_TTSMessageState()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_VivoxCore();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("TTSMessageState"), 0, Get_Z_Construct_UEnum_VivoxCore_TTSMessageState_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "TTSMessageState::Playing", (int64)TTSMessageState::Playing },
				{ "TTSMessageState::Enqueued", (int64)TTSMessageState::Enqueued },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "Comment", "/**\n * \\brief The state of the TTSMessage\n */" },
				{ "Enqueued.Comment", "/**\n     * \\brief The message is waiting to be played in its destination\n     */" },
				{ "Enqueued.Name", "TTSMessageState::Enqueued" },
				{ "Enqueued.ToolTip", "\\brief The message is waiting to be played in its destination" },
				{ "ModuleRelativePath", "Public/ITTSMessage.h" },
				{ "Playing.Comment", "/**\n     * \\brief The message is currently being played in its destination\n     */" },
				{ "Playing.Name", "TTSMessageState::Playing" },
				{ "Playing.ToolTip", "\\brief The message is currently being played in its destination" },
				{ "ToolTip", "\\brief The state of the TTSMessage" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_VivoxCore,
				nullptr,
				"TTSMessageState",
				"TTSMessageState",
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
	static UEnum* TTSDestination_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_VivoxCore_TTSDestination, Z_Construct_UPackage__Script_VivoxCore(), TEXT("TTSDestination"));
		}
		return Singleton;
	}
	template<> VIVOXCORE_API UEnum* StaticEnum<TTSDestination>()
	{
		return TTSDestination_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_TTSDestination(TTSDestination_StaticEnum, TEXT("/Script/VivoxCore"), TEXT("TTSDestination"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_VivoxCore_TTSDestination_Hash() { return 3538233110U; }
	UEnum* Z_Construct_UEnum_VivoxCore_TTSDestination()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_VivoxCore();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("TTSDestination"), 0, Get_Z_Construct_UEnum_VivoxCore_TTSDestination_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "TTSDestination::Default", (int64)TTSDestination::Default },
				{ "TTSDestination::RemoteTransmission", (int64)TTSDestination::RemoteTransmission },
				{ "TTSDestination::LocalPlayback", (int64)TTSDestination::LocalPlayback },
				{ "TTSDestination::RemoteTransmissionWithLocalPlayback", (int64)TTSDestination::RemoteTransmissionWithLocalPlayback },
				{ "TTSDestination::QueuedRemoteTransmission", (int64)TTSDestination::QueuedRemoteTransmission },
				{ "TTSDestination::QueuedLocalPlayback", (int64)TTSDestination::QueuedLocalPlayback },
				{ "TTSDestination::QueuedRemoteTransmissionWithLocalPlayback", (int64)TTSDestination::QueuedRemoteTransmissionWithLocalPlayback },
				{ "TTSDestination::ScreenReader", (int64)TTSDestination::ScreenReader },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "Comment", "/**\n * \\brief Unified selection of output stream and mechanism for TTS injection\n */" },
				{ "Default.Comment", "/**\n     * \\brief Do Not Use. Defined only to work around a bug in UnrealBuildTool.\n     */" },
				{ "Default.Name", "TTSDestination::Default" },
				{ "Default.ToolTip", "\\brief Do Not Use. Defined only to work around a bug in UnrealBuildTool." },
				{ "LocalPlayback.Comment", "/**\n     * \\brief Immediately play back locally on render device (e.g. speakers). Mixes new message with any other ongoing messages.\n     */" },
				{ "LocalPlayback.Name", "TTSDestination::LocalPlayback" },
				{ "LocalPlayback.ToolTip", "\\brief Immediately play back locally on render device (e.g. speakers). Mixes new message with any other ongoing messages." },
				{ "ModuleRelativePath", "Public/ITTSMessage.h" },
				{ "QueuedLocalPlayback.Comment", "/**\n     * \\brief Play back locally on render device (e.g. speakers), or enqueue if there is already an ongoing message playing in this destination.\n     */" },
				{ "QueuedLocalPlayback.Name", "TTSDestination::QueuedLocalPlayback" },
				{ "QueuedLocalPlayback.ToolTip", "\\brief Play back locally on render device (e.g. speakers), or enqueue if there is already an ongoing message playing in this destination." },
				{ "QueuedRemoteTransmission.Comment", "/**\n     * \\brief Send to participants in connected sessions, or enqueue if there is already an ongoing message playing in this destination.\n     */" },
				{ "QueuedRemoteTransmission.Name", "TTSDestination::QueuedRemoteTransmission" },
				{ "QueuedRemoteTransmission.ToolTip", "\\brief Send to participants in connected sessions, or enqueue if there is already an ongoing message playing in this destination." },
				{ "QueuedRemoteTransmissionWithLocalPlayback.Comment", "/**\n     * \\brief Play back locally on render device, and send to participants in connected sessions. Enqueue if there is already an ongoing message playing in this destination.\n     */" },
				{ "QueuedRemoteTransmissionWithLocalPlayback.Name", "TTSDestination::QueuedRemoteTransmissionWithLocalPlayback" },
				{ "QueuedRemoteTransmissionWithLocalPlayback.ToolTip", "\\brief Play back locally on render device, and send to participants in connected sessions. Enqueue if there is already an ongoing message playing in this destination." },
				{ "RemoteTransmission.Comment", "/**\n     * \\brief Immediately send to participants in connected sessions. Mixes new message with any other ongoing messages.\n     */" },
				{ "RemoteTransmission.Name", "TTSDestination::RemoteTransmission" },
				{ "RemoteTransmission.ToolTip", "\\brief Immediately send to participants in connected sessions. Mixes new message with any other ongoing messages." },
				{ "RemoteTransmissionWithLocalPlayback.Comment", "/**\n     * \\brief Immediately play back locally on render device, and send to participants in connected sessions. Mixes new message with any other ongoing messages.\n     */" },
				{ "RemoteTransmissionWithLocalPlayback.Name", "TTSDestination::RemoteTransmissionWithLocalPlayback" },
				{ "RemoteTransmissionWithLocalPlayback.ToolTip", "\\brief Immediately play back locally on render device, and send to participants in connected sessions. Mixes new message with any other ongoing messages." },
				{ "ScreenReader.Comment", "/**\n     * \\brief Immediately play back locally on render device (e.g. speakers). Replaces the currently playing message in this destination.\n     */" },
				{ "ScreenReader.Name", "TTSDestination::ScreenReader" },
				{ "ScreenReader.ToolTip", "\\brief Immediately play back locally on render device (e.g. speakers). Replaces the currently playing message in this destination." },
				{ "ToolTip", "\\brief Unified selection of output stream and mechanism for TTS injection" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_VivoxCore,
				nullptr,
				"TTSDestination",
				"TTSDestination",
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
