#pragma once

#ifdef SLR_PLATFORM_WINDOWS
    #if SLR_DYNAMIC_LINK
        #ifdef SLR_BUILD_DLL
            #define SOLARIS_API __declspec(dllexport)
        #else
            #define SOLARIS_API __declspec(dllimport)
        #endif // SLR_BUILD_DLL
    #else
        #define SOLARIS_API
    #endif // SLR_DYNAMIC_LINK
#else
    #error Solaris supports Windows
#endif // SLR_PLATFORM_WINDOWS

#ifdef SLR_ENABLE_ASSERT
    #define SLR_ASSERT(value, ...) { if (!(value)) { SLR_CORE_LOG(Error, "Assert: {}", __VA_ARGS__); __debugbreak(); } }
#else
    #define SLR_ASSERT(value, ...)
#endif // SLR_ENABLE_ASSERT