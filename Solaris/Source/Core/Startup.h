#pragma once

#include "Log.h"

#ifdef SLR_PLATFORM_WINDOWS

extern Solaris::Application* Solaris::CreateApplication();

int main(int argc, char** argv)
{
    Solaris::Log::init();
    
    auto app = Solaris::CreateApplication();
    app->exec();

    delete app;
    return 0;
}

#endif
