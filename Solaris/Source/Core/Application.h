#pragma once

#include "Core.h"

namespace Solaris
{
    class SOLARIS_API Application
    {
    public:
        Application();
        virtual ~Application();

        void exec();
    };

    Application* create_application();
}
