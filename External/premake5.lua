project "External"
	kind "StaticLib"
	language "C++"
	cppdialect "C++20"
	staticruntime "off"

	targetdir ("%{wks.location}/bin/" .. outputdir.. "/%{prj.name}")
	objdir    ("%{wks.location}/bin-int/" .. outputdir.. "/%{prj.name}")

	includedirs
	{
		"%{wks.location}/External",
		"%{wks.location}/External/assimp/include/",
	}
	
	files
	{
		"%{wks.location}/External/json/**.hpp",
		"%{wks.location}/External/glm/glm/**.hpp",
		"%{wks.location}/External/glm/glm/**.inl",
		"%{wks.location}/External/stb_image/**.h",
		"%{wks.location}/External/stb_image/**.cpp",
		"%{wks.location}/External/assimp/include/assimp/*",
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

