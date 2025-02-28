workspace "moss"
    configurations { "debug", "release" }
    architecture "x86_64"
    location "scripts"

    includedirs { "../mossCore/include", "entt" }
    libdirs { "../mossCore/bin/debug" }
    links { "mossCore", "raylib", "fmt" }

    project "hexagon"
        kind "WindowedApp"
        language "C++"
        cppdialect "C++17"
        targetdir "bin/%{cfg.buildcfg}"
        objdir "build/%{cfg.buildcfg}"

        files { "hexagon/src/**.cpp", "hexagon/generated/src/**.cpp" }
        includedirs { "hexagon/generated/include" }

        filter "configurations:debug"
            defines { "DEBUG" }
            symbols "On"

        filter "configurations:release"
            defines { "NDEBUG" }
            optimize "On"
