project "Core"
	kind "StaticLib"
	language "C++"
	cppdialect "C++20"
	staticruntime "off"

	targetdir ("%{wks.location}/bin/" .. outputdir.. "/%{prj.name}")
	objdir    ("%{wks.location}/bin-int/" .. outputdir.. "/%{prj.name}")
	
	pchheader "pch.h"
	pchsource "src/pch.cpp"

	includedirs
	{
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.spdlog}",
	}

	libdirs 
	{
		"%{wks.location}/External/GLFW/lib-vc2022/",
	}

	files
	{
		"src/**.h",
		"src/**.cpp",
	}

    links
	{
		"GLFW",
		"Glad",
		"External",
	}

	filter "system:windows"
		systemversion "latest"
		staticruntime "off"

		defines
		{
			"GLFW_INCLUDE_NONE"
		}

	filter "configurations:Debug"
		defines "DEBUG=1"
		runtime "Debug"
		symbols "on"


	filter "configurations:Release"
		defines "RELEASE=1"
		runtime "Release"
		optimize "on"