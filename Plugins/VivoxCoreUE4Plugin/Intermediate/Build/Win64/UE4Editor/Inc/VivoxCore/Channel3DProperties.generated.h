// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef VIVOXCORE_Channel3DProperties_generated_h
#error "Channel3DProperties.generated.h already included, missing '#pragma once' in Channel3DProperties.h"
#endif
#define VIVOXCORE_Channel3DProperties_generated_h

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID C0MultiTest_2_Plugins_VivoxCoreUE4Plugin_Source_VivoxCore_Public_Channel3DProperties_h


#define FOREACH_ENUM_EAUDIOFADEMODEL(op) \
	op(EAudioFadeModel::InverseByDistance) \
	op(EAudioFadeModel::LinearByDistance) \
	op(EAudioFadeModel::ExponentialByDistance) 

enum class EAudioFadeModel : uint8;
template<> VIVOXCORE_API UEnum* StaticEnum<EAudioFadeModel>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
