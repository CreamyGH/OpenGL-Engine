project "Core"
	kind "StaticLib"
	language "C++"
	cppdialect "C++20"
	staticruntime "off"

	targetdir ("%{wks.location}/bin/" .. outputdir.. "/%{prj.name}")
	objdir    ("%{wks.location}/bin-int/" .. outputdir.. "/%{prj.name}")
	
	pchheader "pch.h"

	includedirs
	{
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.spdlog}",
		"%{wks.location}/Engine/Core/src",
	}

	files
	{
		"src/**.h",
		"src/**.cpp",
	}

    links
	{
		"External",
		"GLFW",
	}

	filter "system:windows"
			pchsource "src/pch.cpp"
			systemversion "latest"
			staticruntime "off"
			libdirs { "%{wks.location}/External/GLFW/lib-vc2022/" }
			defines { "GLFW_INCLUDE_NONE" }

	filter "system:linux"
			pic "On"
			defines { "GLFW_INCLUDE_NONE" }

	filter "configurations:Debug"
		defines "DEBUG=1"
		runtime "Debug"
		symbols "on"


	filter "configurations:Release"
		defines "RELEASE=1"
		runtime "Release"
		optimize "on"