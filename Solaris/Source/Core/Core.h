#pragma once

#ifdef SLR_PLATFORM_WINDOWS
    #if SLR_DYNAMIC_LINK
        #ifdef SLR_BUILD_DLL
            #define SOLARIS_API __declspec(dllexport)
        #else
            #define SOLARIS_API __declspec(dllimport)
        #endif
    #else
        #define SOLARIS_API
    #endif
#else
    #error Solaris supports Windows
#endif // SLR_PLATFORM_WINDOWS
