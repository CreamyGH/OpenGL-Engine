project "OpenGLBackend"
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
		"%{wks.location}/Engine/Graphics/Backend/OpenGL/src",
		"%{wks.location}/Engine/Graphics/Core/src",
		"%{wks.location}/Engine/Core/src",
	}


	links
	{
		"Core",
		"GraphicsCore",
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
			libdirs { "%{wks.location}/External/GLFW/lib-vc2022/" }
			links { "opengl32.lib" }
			defines { "GLFW_INCLUDE_NONE" }

	filter "system:linux"
			pic "On"
			links { "GL", "pthread", "dl", "X11" }
			defines { "GLFW_INCLUDE_NONE" }

	filter "configurations:Debug"
		defines "DEBUG=1"
		runtime "Debug"
		symbols "on"


	filter "configurations:Release"
		defines "RELEASE=1"
		runtime "Release"
		optimize "on"