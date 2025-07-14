// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Lira : ModuleRules
{
	public Lira(ReadOnlyTargetRules Target) : base(Target)
	{
		PrivateDependencyModuleNames.AddRange(new string[] {  });
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { 
			"Core", 
			"CoreUObject", 
			"Engine", 
			"InputCore", 
			"EnhancedInput", 
			"GameplayAbilities", 
			"GameplayTasks", 
			"GameplayTags", 
			"DeveloperSettings",
			"AIModule",
			"GameplayTasks",
			"GeometryScriptingCore"
		});
	}
}
