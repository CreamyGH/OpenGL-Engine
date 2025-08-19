project "Assets"
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
		"%{IncludeDir.stb_image}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.assimp}",
		"%{wks.location}/External/assimp/include",
		"%{wks.location}/Engine/Core/src",
		"%{wks.location}/Engine/Assets/src",
	}

	links
	{
		"Core",
		"External",
		"Glad",
		"GLFW",
	}

	files
	{
		"src/**.h",
		"src/**.cpp",
	}

	filter "system:windows"
			systemversion "latest"
			staticruntime "off"
			links { "opengl32.lib" }

	filter "system:linux"
			pic "On"
			links { "GL", "pthread", "dl", "X11" }

	filter "configurations:Debug"
		defines "DEBUG=1"
		runtime "Debug"
		symbols "on"


	filter "configurations:Release"
		defines "RELEASE=1"
		runtime "Release"
		optimize "on"