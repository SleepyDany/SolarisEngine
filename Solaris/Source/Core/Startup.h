#pragma once

#ifdef SLR_PLATFORM_WINDOWS

extern Solaris::Application* Solaris::CreateApplication();

int main(int argc, char** argv)
{
    auto app = Solaris::CreateApplication();
    app->exec();

    delete app;
    return 0;
}

#endif
