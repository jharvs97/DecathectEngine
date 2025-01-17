project "Glad"
	kind "StaticLib"
	language "C"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"include/glad/glad.h",
        "include/KHR/khrpla.h",
        "src/glad.c"
	}

    includedirs
    {
        "include"
    }

	filter "system:linux"
		pic "On"

		systemversion "latest"
		staticruntime "On"


	filter "system:windows"
		systemversion "latest"
		staticruntime "On"
    
    filter {"system:windows", "configurations:Release"}
        buildoptions "/MT"
