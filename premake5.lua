workspace "AndroidPromptKit"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "AndroidPromptKit"
	kind "WindowedApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/*.cpp",
		"src/*.h",
    	"thirdparty/imgui/*.cpp"
	}

	includedirs
	{
		"thirdparty/glfw/include",
    	"thirdparty/imgui"
	}

	links
	{
		"thirdparty/glfw/lib/glfw3.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"
