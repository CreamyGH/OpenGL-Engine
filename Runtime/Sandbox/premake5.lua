project "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++20"

	targetdir ("%{wks.location}/bin/" .. outputdir.. "/%{prj.name}")
	objdir    ("%{wks.location}/bin-int/" .. outputdir.. "/%{prj.name}")
	
	includedirs
	{
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.spdlog}",
		"%{wks.location}/Engine/Core/src",
		"%{wks.location}/Engine/Renderer/src",
		"%{wks.location}/Engine/Assets/src",
	}
	
	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	libdirs 
	{
		"%{wks.location}/External/GLFW/lib-vc2022/",
	}

	links
	{
		"GLFW",
		"Glad",
		"Core",
		"Renderer",
		"Assets",
		"External",
		"opengl32.lib",
	}

	files
	{
		"src/**.h",
		"src/**.cpp",
	}

	postbuildcommands
	{
	    'xcopy /Q /E /Y /I "%{wks.location}Runtime\\"%{prj.name}"\\Resources" "%{cfg.targetdir}\\Resources\\"',
	}

	filter { "system:windows", "configurations:Debug" }
		postbuildcommands {
			'{COPY} "%{wks.location}External/assimp/bin/windows/Debug/assimp-vc143-mtd.dll" %{cfg.targetdir}',
		}
		libdirs {
			"%{wks.location}/External/assimp/bin/windows/Debug",
		}
		links {
			"assimp-vc143-mtd.lib"
		}

	filter { "system:windows", "configurations:Release" }
		postbuildcommands {
			'{COPY} "../../External/assimp/bin/windows/Release/assimp-vc143-mt.dll" "%{cfg.targetdir}"',
		}
		libdirs {
			"%{wks.location}/External/assimp/bin/windows/Release",
		}
		links {
			"assimp-vc143-mt.lib"
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