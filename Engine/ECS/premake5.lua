 project "Renderer"
	kind "StaticLib"
	language "C++"
	cppdialect "C++20"
	staticruntime "off"

	targetdir ("%{wks.location}/bin/" .. outputdir.. "/%{prj.name}")
	objdir    ("%{wks.location}/bin-int/" .. outputdir.. "/%{prj.name}")
	
	includedirs
	{
		"%{IncludeDir.stb_image}",
		"%{wks.location}/External/",
		"%{wks.location}/External/glm",
		"%{wks.location}/External/assimp/include",
		"%{wks.location}/Engine/Core/Source",
		"%{wks.location}/Engine/Assets/Source",
		"%{wks.location}/Engine/Graphics/Source",
	}

	libdirs 
	{
		"%{wks.location}/External/vulkan_lib/",
	}

	links
	{
		"vulkan-1.lib",
		"External",
		"Core",
	}

	files
	{
		"**.h",
		"**.cpp",
	}

	filter "system:windows"
		systemversion "latest"
		staticruntime "off"

	filter "configurations:Debug"
		defines "DEBUG=1"
		runtime "Debug"
		symbols "on"
		links
		{
			"shaderc_sharedd.lib",
			"shaderc_utild.lib",
			"spirv-cross-cored.lib",
			"spirv-cross-glsld.lib",
			"SPIRV-Toolsd.lib",
		}

	filter "configurations:Release"
		defines "RELEASE=1"
		runtime "Release"
		optimize "on"
		links
		{
			"shaderc_shared.lib",
			"shaderc_util.lib",
			"spirv-cross-core.lib",
			"spirv-cross-glsl.lib",
			"SPIRV-Toolsd.lib",
		}

