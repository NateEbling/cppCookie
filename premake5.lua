workspace "Cookie"
    configurations { "Debug", "Release" }
    startproject "Cookie"

    flags { "MultiProcessorCompile" }
    
    filter "configurations:Debug" 
        defines { "DEBUG", "DEBUG_SHADER" }
        symbols "on"

    filter "configurations:Release"
        defines { "RELEASE" }
        optimize "Speed"
        flags { "LinkTimeOptimization" 
    } 

project "Cookie"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
        architecture "x86_64"

    targetdir "bin/%{cfg.buildcfg}"
    objdir "bin-int/%{cfg.buildcfg}"

    includedirs { 
        "Cookie/include", 
        "Cookie/vendor/glad/include", 
        "Cookie/vendor/glfw/include", 
        "Cookie/vendor/glm/", 
        "Cookie/vendor/imgui/", 
        "Cookie/vendor/imgui/examples",
        "Cookie/vendor/robinHoodHashing",
    }
    
    files {
        "Cookie/src/**.cpp",
        "Cookie/src/**.hpp",
        "Cookie/include/**.h",
        "Cookie/include/**.hpp",
    
    }

    links { "GLFW", "GLAD", "ImGui" }

    filter "system:windows"
        defines { "_WINDOWS" }


newaction {
    trigger = "clean",
    description = "Remove all binaries, intermediate binaries, and vs files.",
    execute = function()
        print("Removing binaries")
        os.rmdir("./bin")
        print("Removing intermediate binaries")
        os.rmdir("./bin-int")
        print("Removing project files")
        os.rmdir("./.vs")
        os.remove("**.sln")
        os.remove("**.vcxproj")
        os.remove("**.vcxproj.filters")
        os.remove("**.vcxproj.user")
        print("Done")
    end
}

include "Cookie/vendor/glfw.lua"
include "Cookie/vendor/glad.lua"
include "Cookie/vendor/glm.lua"
include "Cookie/vendor/imgui.lua"