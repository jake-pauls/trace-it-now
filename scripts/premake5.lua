workspace "trace-it-now"
    configurations { "Debug", "Release" }
    architecture "x86_64"
    language "C++"
    cppdialect "C++20"

    targetdir "%{wks.location}/../build/%{cfg.buildcfg}"
    objdir "%{wks.location}/../intermediate/%{cfg.buildcfg}"

    filter "Debug"
        defines { "DEBUG" }
        optimize "Off"
        symbols "On"
    filter "Release"
        defines { "NDEBUG" }
        optimize "On"
        symbols "Off"

project "trace-it-now"
    kind "ConsoleApp"
    language "C++"

    files {
        "%{wks.location}/../src/**.cpp",
        "%{wks.location}/../src/**.hpp",
    }

