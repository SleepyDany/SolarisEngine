#pragma once

#ifdef SLR_PLATFORM_WINDOWS
    #ifdef SLR_BUILD_DLL
        #define SOLARIS_API __declspec(dllexport)
    #else
        #define SOLARIS_API __declspec(dllimport)
    #endif
#else
    #error Solaris supports Windows
#endif // SLR_PLATFORM_WINDOWS

namespace Solaris
{
    SOLARIS_API void print();
}
