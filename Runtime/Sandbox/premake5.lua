project "Sandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"

    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
    objdir    ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "src/**.h",
        "src/**.cpp",
    }

    includedirs {
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.glm}",
        "%{IncludeDir.spdlog}",
        "%{wks.location}/Engine/Core/src",
        "%{wks.location}/Engine/Renderer/src",
        "%{wks.location}/Engine/Assets/src",
    }

    defines { "_CRT_SECURE_NO_WARNINGS" }

    links {
        "Assets",
        "Renderer",
        "Core",
        "External",
        "Glad",
        "GLFW",
    }

    filter "system:windows"
        systemversion "latest"
        staticruntime "off"
        defines { "GLFW_INCLUDE_NONE", "WIN32_LEAN_AND_MEAN", "NOMINMAX" }
        libdirs { "%{wks.location}/External/GLFW/lib-vc2022/" }
        links { "opengl32.lib" }
        postbuildcommands {
            '{COPYDIR} "%{wks.location}/Runtime/%{prj.name}/Resources" "%{cfg.targetdir}/Resources"'
        }

    filter { "system:windows", "configurations:Debug" }
        runtime "Debug"
        symbols "on"
        libdirs { "%{wks.location}/External/assimp/bin/windows/Debug" }
        links { "assimp-vc143-mtd.lib" }
        postbuildcommands {
            '{COPYFILE} "%{wks.location}/External/assimp/bin/windows/Debug/assimp-vc143-mtd.dll" "%{cfg.targetdir}/assimp-vc143-mtd.dll"'
        }

    filter { "system:windows", "configurations:Release" }
        runtime "Release"
        optimize "on"
        libdirs { "%{wks.location}/External/assimp/bin/windows/Release" }
        links { "assimp-vc143-mt.lib" }
        postbuildcommands {
            '{COPYFILE} "%{wks.location}/External/assimp/bin/windows/Release/assimp-vc143-mt.dll" "%{cfg.targetdir}/assimp-vc143-mt.dll"'
        }

    filter "system:linux"
        pic "On"
        defines { "GLFW_INCLUDE_NONE" }
        includedirs { "%{wks.location}/External/assimp/include" }
        libdirs { "%{wks.location}/External/assimp/bin/linux" }
        links { "GL", "pthread", "dl", "X11", "assimp" }
        linkoptions { "-Wl,--enable-new-dtags", "-Wl,-rpath,'$ORIGIN'" }
        postbuildcommands {
            --'{COPYDIR} "%{wks.location}/Runtime/%{prj.name}/Resources" "%{cfg.targetdir}/Resources"',
            '{COPYFILE} "%{wks.location}/External/assimp/bin/linux/libassimp.so.5" "%{cfg.targetdir}/libassimp.so.5"',
            '{COPYFILE} "%{wks.location}/External/assimp/bin/linux/libassimp.so" "%{cfg.targetdir}/libassimp.so"'
        }

    filter "configurations:Debug"
        defines "DEBUG=1"
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines "RELEASE=1"
        runtime "Release"
        optimize "on"