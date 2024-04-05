workspace "Cookie"
    location "../"
    configurations { "Debug", "Development", "Release" }
    startproject "Cookie"

    filter "configurations:Debug" 
        defines { "DEBUG" }
        flags { "MultiProcessorCompile" }
        optimize "Off"
        symbols "On"

    filter "configurations:Development"
        defines { "DEBUG" }
        flags { "MultiProcessorCompile" }
        optimize "Speed"
        symbols "On"

    filter "configurations:Release"
        optimize "Speed"
        flags { "LinkTimeOptimization", "MultiProcessorCompile" }
        symbols "Off"
    
    toolset "gcc"

project "Cookie"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"
        architecture "x86_64"

    targetdir "../bin/%{cfg.buildcfg}"
    objdir "../bin-int/%{cfg.buildcfg}"

    includedirs { 
        "../third_party/imgui/",
        "../third_party/imgui/examples",
        "../third_party/glad/include",
        "../third_party/glfw/include",
    }

    files {
        "Cookie/src/**.cpp",
        "Cookie/src/**.hpp",
        "Cookie/src/**.h",
    }

    links { "GLFW", "GLAD", "ImGui" }

    filter "system:windows"
        defines { "_WINDOWS" }


newaction {
    trigger = "clean",
    description = "Remove all binaries, intermediate binaries, and vs files.",
    execute = function()
        print("Removing binaries")
        os.rmdir(".././bin")
        print("Removing intermediate binaries")
        os.rmdir(".././bin-int")
        print("Removing project files")
        os.rmdir(".././.vs")
        os.remove("../**.sln")
        os.remove("../**.vcxproj")
        os.remove("../**.vcxproj.filters")
        os.remove("../**.vcxproj.user")
        print("Done")
    end
}

include "../third_party/imgui.lua"
include "../third_party/glfw.lua"
include "../third_party/glad.lua"