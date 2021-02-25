// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "VivoxCore/Private/AudioDeviceImpl.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAudioDeviceImpl() {}
// Cross Module References
	VIVOXCORE_API UEnum* Z_Construct_UEnum_VivoxCore_DeviceType();
	UPackage* Z_Construct_UPackage__Script_VivoxCore();
// End Cross Module References
	static UEnum* DeviceType_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_VivoxCore_DeviceType, Z_Construct_UPackage__Script_VivoxCore(), TEXT("DeviceType"));
		}
		return Singleton;
	}
	template<> VIVOXCORE_API UEnum* StaticEnum<DeviceType>()
	{
		return DeviceType_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_DeviceType(DeviceType_StaticEnum, TEXT("/Script/VivoxCore"), TEXT("DeviceType"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_VivoxCore_DeviceType_Hash() { return 3198948597U; }
	UEnum* Z_Construct_UEnum_VivoxCore_DeviceType()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_VivoxCore();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("DeviceType"), 0, Get_Z_Construct_UEnum_VivoxCore_DeviceType_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "DeviceType::NullDevice", (int64)DeviceType::NullDevice },
				{ "DeviceType::SpecificDevice", (int64)DeviceType::SpecificDevice },
				{ "DeviceType::DefaultSystemDevice", (int64)DeviceType::DefaultSystemDevice },
				{ "DeviceType::DefaultCommunicationDevice", (int64)DeviceType::DefaultCommunicationDevice },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "Comment", "/**\n * \\brief The type of device\n */" },
				{ "DefaultCommunicationDevice.Comment", "/**\n     * This type means to use what ever the system has configured as a default communication device, at the time of the call.\n     * Don't switch devices mid-call if the default communication device changes.\n     */" },
				{ "DefaultCommunicationDevice.Name", "DeviceType::DefaultCommunicationDevice" },
				{ "DefaultCommunicationDevice.ToolTip", "This type means to use what ever the system has configured as a default communication device, at the time of the call.\nDon't switch devices mid-call if the default communication device changes." },
				{ "DefaultSystemDevice.Comment", "/**\n     * This type means to use what ever the system has configured as a default, at the time of the call.\n     * Don't switch devices mid-call if the default system device changes.\n     */" },
				{ "DefaultSystemDevice.Name", "DeviceType::DefaultSystemDevice" },
				{ "DefaultSystemDevice.ToolTip", "This type means to use what ever the system has configured as a default, at the time of the call.\nDon't switch devices mid-call if the default system device changes." },
				{ "ModuleRelativePath", "Private/AudioDeviceImpl.h" },
				{ "NullDevice.Comment", "/**\n     * This is the null device, which means that either input or output from/to that device will not occur.\n     */" },
				{ "NullDevice.Name", "DeviceType::NullDevice" },
				{ "NullDevice.ToolTip", "This is the null device, which means that either input or output from/to that device will not occur." },
				{ "SpecificDevice.Comment", "/**\n     * This type is a specific device.\n     */" },
				{ "SpecificDevice.Name", "DeviceType::SpecificDevice" },
				{ "SpecificDevice.ToolTip", "This type is a specific device." },
				{ "ToolTip", "\\brief The type of device" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_VivoxCore,
				nullptr,
				"DeviceType",
				"DeviceType",
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
