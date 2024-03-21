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
    kind "StaticLib"
    language "C++"
    cppdialect "C++20"
    staticruntime "On"

    targetdir ("Binaries/" .. outputdir .. "/%{prj.name}")
    objdir ("Intermediate/" .. outputdir .. "/%{prj.name}")
    
    pchheader "slrpch.h"
    pchsource "Solaris/Source/slrpch.cpp"

    files
    {
        "%{prj.name}/Source/**.h",
        "%{prj.name}/Source/**.cpp"
    }

    includedirs
    {
        "Solaris/Source",
        "Solaris/ThirdParty/spdlog/include"
    }

    filter "system:windows"
        systemversion("latest")

        defines
        {
            "SLR_PLATFORM_WINDOWS",
            "SLR_BUILD_DLL",
            -- for dynamic linking .dll and make prj SharedLib, etc
            -- "SLR_DYNAMIC_LINK"
            
            -- silence warnings
            "_SILENCE_STDEXT_ARR_ITERS_DEPRECATION_WARNING",
            "_SILENCE_ALL_MS_EXT_DEPRECATION_WARNINGS"
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
    cppdialect "C++20"
    staticruntime "On"
    
    targetdir ("Binaries/" .. outputdir .. "/%{prj.name}")
    objdir ("Intermediate/" .. outputdir .. "/%{prj.name}")
    
    defines
    {
        "SLR_PLATFORM_WINDOWS",
        
        -- silence warnings
        "_SILENCE_STDEXT_ARR_ITERS_DEPRECATION_WARNING",
        "_SILENCE_ALL_MS_EXT_DEPRECATION_WARNINGS"
    }

    files
    {
        "%{prj.name}/Source/**.h",
        "%{prj.name}/Source/**.cpp"
    }
    
    includedirs
    {
        "Solaris/Source",
        "Solaris/ThirdParty/spdlog/include"
    }

    links
    {
	    "Solaris"
    }

    filter "system:windows"
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