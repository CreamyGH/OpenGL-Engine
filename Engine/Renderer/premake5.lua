project "Renderer"
	kind "StaticLib"
	language "C++"
	cppdialect "C++20"
	staticruntime "off"

	targetdir ("%{wks.location}/bin/" .. outputdir.. "/%{prj.name}")
	objdir    ("%{wks.location}/bin-int/" .. outputdir.. "/%{prj.name}")
	
	includedirs
	{
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.spdlog}",
		"%{wks.location}/Engine/Core/src",
		"%{wks.location}/Engine/Assets/src",
	}

	libdirs 
	{
		"%{wks.location}/External/GLFW/lib-vc2022/",
	}

	links
	{
		"Assets",
		"Core",
		"External",
		"Glad",
		"GLFW",
		"opengl32.lib",
	}

	files
	{
		"src/**.h",
		"src/**.cpp",
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