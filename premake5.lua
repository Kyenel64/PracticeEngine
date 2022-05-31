workspace "AStar" -- Create solution called AStar
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}" 

project "AStar" -- Create project called AStar
    location "AStar" -- Create folder called AStar
    kind "SharedLib" -- Type is DLL
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}") -- Output directory
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}") -- Object directory

    files -- Files to include in the project
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs -- All includes
    {
        "%{prj.name}/vendor/spdlog/include",
        "%{prj.name}/src"
    }

    filter "system:windows" -- Commands for windows
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines -- Defines
        {
            "AS_PLATFORM_WINDOWS",
            "AS_BUILD_DLL"
        }

        postbuildcommands -- Post build: copy dll to output dir
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

    filter "configurations:Debug"
        defines "AS_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "AS_RELEASE"
        symbols "On"

    filter "configurations:Dist"
        defines "AS_DIST"
        symbols "On"


        
project "Sandbox" -- Create Sandbox project
        location "Sandbox"
        kind "ConsoleApp"
        language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "AStar/vendor/spdlog/include",
        "AStar/src"
    }

    links -- Projects/Libraries to link
    {
        "AStar"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "AS_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "AS_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "AS_RELEASE"
        symbols "On"

    filter "configurations:Dist"
        defines "AS_DIST"
        symbols "On"