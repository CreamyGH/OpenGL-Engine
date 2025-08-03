workspace "OpenGL-Engine"
	architecture "x64"
	configurations { "Debug", "Release" }
	startproject "Sandbox"

	flags
	{
		"MultiProcessorCompile"
	}

	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

	IncludeDir = {}
	IncludeDir["GLFW"] = "%{wks.location}/External/glfw/include"
	IncludeDir["Glad"] = "%{wks.location}/External/Glad/include"
	IncludeDir["glm"] = "%{wks.location}/External/glm"
	IncludeDir["stb_image"] = "%{wks.location}/External/stb_image"
	IncludeDir["entt"] = "%{wks.location}/External/entt/src"
	IncludeDir["spdlog"] = "%{wks.location}/External/spdlog/include"
	IncludeDir["assimp"] = "%{wks.location}/External/assimp/include"

group "Dependencies"
	include "External/GLFW"
	include "External/Glad"
	include "External"

group "Engine"
	include "Engine/Core"
	include "Engine/Assets"
	include "Engine/Renderer"
	include "Engine/ECS"

group "Runtime"
	include "Runtime/Sandbox"