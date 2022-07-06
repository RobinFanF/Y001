workspace "hezzle"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}" 

--include directories relative to root folder

IncludeDir = {}
IncludeDir["GLFW"] = "hezzle/third-party/GLFW/include"
IncludeDir["Glad"] = "hezzle/third-party/Glad/include"
IncludeDir["ImGui"] = "hezzle/third-party/imgui"
IncludeDir["glm"] = "hezzle/third-party/glm"

include "hezzle/third-party/GLFW"
include "hezzle/third-party/Glad"
include "hezzle/third-party/imgui"
 
project "hezzle"

    location "hezzle"

    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir("bin/" .. outputdir .."/%{prj.name}")
    objdir("bin-int/" .. outputdir .."/%{prj.name}")

    pchheader "hzpch.h"
    pchsource "hezzle/src/hzpch.cpp"


    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
        "%{prj.name}/third-party/glm/glm/**.hpp",
        "%{prj.name}/third-party/glm/glm/**.inl"
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/third-party/spdlog/include",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.ImGui}",
        "%{IncludeDir.glm}"
    }

    links
    {
        "GLFW",
        "Glad",
        "ImGui",
        "opengl32.lib"
    }


    filter "system:windows"
        
        systemversion "latest"

        defines
        {
            "HZ_PLATFORM_WINDOWS",
            "HZ_BUILD_DLL",
            "GLFW_INCLUDE_NONE"
        }


        filter "configurations:Debug"
            defines "HZ_DEBUG"
            symbols "on"

        filter "configurations:Release"
            defines "HZ_Release"
            optimize "on"

        filter "configurations:Dist"
            defines "HZ_Dist"
            optimize "on"


project "SandBox"

        location "SandBox"

        kind "ConsoleApp"
        language "C++"
        cppdialect "C++17"
        staticruntime "on"

        targetdir("bin/" .. outputdir .."/%{prj.name}")
        objdir("bin-int/" .. outputdir .."/%{prj.name}")

        files
        {
            "%{prj.name}/src/**.h",
            "%{prj.name}/src/**.cpp",
        }

        includedirs
        {
            "hezzle/third-party/spdlog/include",
            "hezzle/src",
            "%{IncludeDir.glm}"
        }

        links
        {
            "hezzle"
        }


        filter "system:windows"

            systemversion "latest"

            defines
            {
                "HZ_PLATFORM_WINDOWS"
            }

        filter "configurations:Debug"
            defines "HZ_DEBUG"
            symbols "on"

        filter "configurations:Release"
            defines "HZ_Release"
            optimize "on"

        filter "configurations:Dist"
            defines "HZ_Dist"
            optimize "on"


                           