using UnrealBuildTool;
using System.Collections.Generic;

public class ModuleAndPluginTarget : TargetRules
{
	public ModuleAndPluginTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V4;
		ExtraModuleNames.AddRange(new string[] { "ModuleAndPlugin", "Test" });
	}
}
