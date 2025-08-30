project "GraphicsCore"
	kind "StaticLib"
	language "C++"
	cppdialect "C++20"
	staticruntime "off"

	targetdir ("%{wks.location}/bin/" .. outputdir.. "/%{prj.name}")
	objdir    ("%{wks.location}/bin-int/" .. outputdir.. "/%{prj.name}")
	
	includedirs
	{
		"%{IncludeDir.glm}",
		"%{IncludeDir.spdlog}",
		"%{wks.location}/Engine/Graphics/Core/src",
		"%{wks.location}/Engine/Core/src",
	}


	links
	{
		"Core",
		"External",
	}

	files
	{
		"src/**.h",
		"src/**.cpp",
	}

	filter "system:windows"
			systemversion "latest"
			staticruntime "off"

	filter "system:linux"
			pic "On"

	filter "configurations:Debug"
		defines "DEBUG=1"
		runtime "Debug"
		symbols "on"


	filter "configurations:Release"
		defines "RELEASE=1"
		runtime "Release"
		optimize "on"