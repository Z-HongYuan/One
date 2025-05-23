// Copyright longlt00502@gmail.com 2023. All rights reserved.
using UnrealBuildTool;
public class FreeBoneSnapper : ModuleRules
{
	public FreeBoneSnapper(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		PrivateIncludePaths.AddRange(
			new string[] {
			}
			);
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"Projects",
				"EditorSubsystem",
				"EditorFramework",
				"UnrealEd",
				"CoreUObject",
				"Engine",
				"Persona",
				"Core",
				"IKRig",
			}
			);
	}
}
