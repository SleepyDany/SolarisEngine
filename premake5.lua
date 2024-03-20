workspace "Solaris"
    architecture "x64"

    configurations
    {
        "Debug",
        "Development",
        "Release"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-------
project "Solaris"
    location "Solaris"
    kind "SharedLib"
    language "C++"

    targetdir ("Binaries/" .. outputdir .. "/%{prj.name}")
    objdir ("Intermediate/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/Source/**.h",
        "%{prj.name}/Source/**.cpp"
    }

    includedirs
    {
        "Source/"
    }

    postbuildcommands
    {
        "IF NOT EXIST %[Binaries/" .. outputdir .. "/Playground/] mkdir %[Binaries/" .. outputdir .. "/Playground/]",
        "{COPYFILE} %{cfg.buildtarget.relpath} %[Binaries/" .. outputdir .. "/Playground/]"
    }

    filter "system:windows"
		cppdialect "C++20"
        staticruntime "On"
        systemversion("latest")

        defines
        {
            "SLR_PLATFORM_WINDOWS",
            "SLR_BUILD_DLL"
        }

    filter "configurations:Debug"
        defines "SLR_DEBUG"
        symbols "On"

    filter "configurations:Development"
        defines "SLR_DEVELOPMENT"
        optimize "On"
    
    filter "configurations:Release"
        defines "SLR_RELEASE"
        optimize "On"

-------
project "Playground"
    location "Playground"
    kind "ConsoleApp"
    language "C++"
    
    targetdir ("Binaries/" .. outputdir .. "/%{prj.name}")
    objdir ("Intermediate/" .. outputdir .. "/%{prj.name}")
    
    defines
    {
        "SLR_PLATFORM_WINDOWS"
    }

    files
    {
        "%{prj.name}/Source/**.h",
        "%{prj.name}/Source/**.cpp"
    }
    
    includedirs
    {
        "Solaris/Source"
    }

    links
    {
	    "Solaris"
    }

    filter "system:windows"
        cppdialect "C++20"
        staticruntime "On"
		systemversion("latest")

    filter "configurations:Debug"
        defines "SLR_DEBUG"
        symbols "On"
    
    filter "configurations:Development"
        defines "SLR_DEVELOPMENT"
        optimize "On"
    
    filter "configurations:Release"
        defines "SLR_RELEASE"
        optimize "On"