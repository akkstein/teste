// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef VIVOXCORE_ITTSMessage_generated_h
#error "ITTSMessage.generated.h already included, missing '#pragma once' in ITTSMessage.h"
#endif
#define VIVOXCORE_ITTSMessage_generated_h

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID C0MultiTest_2_Plugins_VivoxCoreUE4Plugin_Source_VivoxCore_Public_ITTSMessage_h


#define FOREACH_ENUM_TTSMESSAGESTATE(op) \
	op(TTSMessageState::Playing) \
	op(TTSMessageState::Enqueued) 

enum class TTSMessageState : uint8;
template<> VIVOXCORE_API UEnum* StaticEnum<TTSMessageState>();

#define FOREACH_ENUM_TTSDESTINATION(op) \
	op(TTSDestination::Default) \
	op(TTSDestination::RemoteTransmission) \
	op(TTSDestination::LocalPlayback) \
	op(TTSDestination::RemoteTransmissionWithLocalPlayback) \
	op(TTSDestination::QueuedRemoteTransmission) \
	op(TTSDestination::QueuedLocalPlayback) \
	op(TTSDestination::QueuedRemoteTransmissionWithLocalPlayback) \
	op(TTSDestination::ScreenReader) 

enum class TTSDestination : uint8;
template<> VIVOXCORE_API UEnum* StaticEnum<TTSDestination>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
