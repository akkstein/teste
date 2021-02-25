// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class C0MultiTest : ModuleRules
{
	public C0MultiTest(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", 
			"CoreUObject", 
			"Engine",
			"InputCore", 
			"VivoxCore", 
			"HeadMountedDisplay" });

		if (Target.Type != TargetRules.TargetType.Server && Target.Platform == UnrealTargetPlatform.Win64)
		{
			PublicDefinitions.Add("WITH_VIVOXCORE=1");
			PrivateDependencyModuleNames.AddRange(new string[] { "VivoxCore" });
		}
		else
		{
			PublicDefinitions.Add("WITH_VIVOXCORE=0");
		}
	}
}