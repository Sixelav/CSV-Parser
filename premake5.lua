-- premake5.lua
workspace "Example"
	location "Example"
	configurations { "Debug", "Release" }
	architecture "x86_64"

	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

	includedirs { "CSV/inc/" }
	

project "Example"	
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++14"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-obj/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.cpp",
		"CSV/src/**.cpp"
	}

	filter "system:windows"
		defines { "WINDOWS" }
		systemversion "latest"

	filter "configurations:Debug"
		defines { "DEBUG" }
		symbols "On"

	filter "configurations:Release"
		defines { "RELEASE" }
		optimize "On"