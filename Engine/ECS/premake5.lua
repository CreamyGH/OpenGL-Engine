project "ECS"
	kind "StaticLib"
	language "C++"
	cppdialect "C++20"
	staticruntime "off"

	targetdir ("%{wks.location}/bin/" .. outputdir.. "/%{prj.name}")
	objdir    ("%{wks.location}/bin-int/" .. outputdir.. "/%{prj.name}")
	
	includedirs
	{
		"%{IncludeDir.entt}",
		"%{IncludeDir.glm}",
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
	}

	filter "system:windows"
		systemversion "latest"
		staticruntime "off"

	filter "configurations:Debug"
		defines "DEBUG=1"
		runtime "Debug"
		symbols "on"


	filter "configurations:Release"
		defines "RELEASE=1"
		runtime "Release"
		optimize "on"