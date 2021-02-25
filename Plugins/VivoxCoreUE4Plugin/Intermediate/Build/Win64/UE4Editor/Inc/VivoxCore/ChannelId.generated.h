// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef VIVOXCORE_ChannelId_generated_h
#error "ChannelId.generated.h already included, missing '#pragma once' in ChannelId.h"
#endif
#define VIVOXCORE_ChannelId_generated_h

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID C0MultiTest_2_Plugins_VivoxCoreUE4Plugin_Source_VivoxCore_Public_ChannelId_h


#define FOREACH_ENUM_CHANNELTYPE(op) \
	op(ChannelType::NonPositional) \
	op(ChannelType::Positional) \
	op(ChannelType::Echo) 

enum class ChannelType : uint8;
template<> VIVOXCORE_API UEnum* StaticEnum<ChannelType>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
