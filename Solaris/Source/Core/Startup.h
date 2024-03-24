#pragma once

#include "Log.h"

#ifdef SLR_PLATFORM_WINDOWS

extern Solaris::Application* Solaris::create_application();

int main(int argc, char** argv)
{
    Solaris::Log::init();
    
    auto app = Solaris::create_application();
    app->exec();

    delete app;
    return 0;
}

#endif
