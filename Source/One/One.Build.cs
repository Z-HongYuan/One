// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class One : ModuleRules
{
	public One(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", //基本引擎模块
			"GameplayAbilities", "GameplayTags", "GameplayTasks", //用于游戏能力系统
			"GameplayDebugger", //用于游戏调试
			"GameplayCameras" //用于游戏相机
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}