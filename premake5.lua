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

include "hezzle/third-party/GLFW"
 
project "hezzle"

    location "hezzle"

    kind "SharedLib"
    language "C++"

    targetdir("bin/" .. outputdir .."/%{prj.name}")
    objdir("bin-int/" .. outputdir .."/%{prj.name}")

    pchheader "hzpch.h"
    pchsource "hezzle/src/hzpch.cpp"


    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/third-party/spdlog/include",
        "%{IncludeDir.GLFW}"
    }

    links
    {
        "GLFW",
        "opengl32.lib"
    }


    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "HZ_PLATFORM_WINDOWS",
            "HZ_BUILD_DLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/SandBox")
        }

        filter "configurations:Debug"
            defines "HZ_DEBUG"
            symbols "On"

        filter "configurations:Release"
            defines "HZ_Release"
            optimize "On"

        filter "configurations:Dist"
            defines "HZ_Dist"
            optimize "On"


project "SandBox"

        location "SandBox"

        kind "ConsoleApp"
        language "C++"

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
            "hezzle/src"
        }

        links
        {
            "hezzle"
        }


        filter "system:windows"
            cppdialect "C++17"
            staticruntime "On"
            systemversion "latest"

            defines
            {
                "HZ_PLATFORM_WINDOWS"
            }

            filter "configurations:Debug"
                defines "HZ_DEBUG"
                symbols "On"

            filter "configurations:Release"
                defines "HZ_Release"
                optimize "On"

            filter "configurations:Dist"
                defines "HZ_Dist"
                optimize "On"