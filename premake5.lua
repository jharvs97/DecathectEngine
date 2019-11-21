workspace "DecathectEngine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "DecathectEngine/vendor/GLFW/include"
IncludeDir["Glad"] = "DecathectEngine/vendor/Glad/include"
IncludeDir["ImGui"] = "DecathectEngine/vendor/imgui"

include "DecathectEngine/vendor/GLFW"
include "DecathectEngine/vendor/Glad"
include "DecathectEngine/vendor/imgui"

project "DecathectEngine"
	location "DecathectEngine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "dcthctpch.h"
	pchsource "DecathectEngine/src/dcthctpch.cpp"

	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
        "%{IncludeDir.ImGui}"
	}

	links
	{
		"GLFW",
		"Glad",
        "ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"DCTHCT_PLATFORM_WINDOWS",
			"DCTHCT_BUILD_DLL", 
            "DCTHCT_ENABLE_ASSERTS",
            "GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "HZ_DEBUG"
        buildoptions "/MDd"
		symbols "On"
	
	filter "configurations:Release"
		defines "HZ_RELEASE"
        buildoptions "/MD"
		optimize "On"
	
	filter "configurations:Dist"
		defines "HZ_DIST"
        buildoptions "/MD"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	links
	{
		"DecathectEngine"
	}

	includedirs
	{
		"DecathectEngine/vendor/spdlog/include",
		"DecathectEngine/src"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"DCTHCT_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "HZ_DEBUG"
        buildoptions "/MDd"
		symbols "On"
	
	filter "configurations:Release"
		defines "HZ_RELEASE"
        buildoptions "/MD"
		optimize "On"
	
	filter "configurations:Dist"
		defines "HZ_DIST"
        buildoptions "/MD"
		optimize "On"
	


	