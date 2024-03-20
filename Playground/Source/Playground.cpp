#include "Solaris.h"

class Playground : public Solaris::Application
{
public:
    Playground()
    {
    }

    ~Playground()
    {
    }
};

Solaris::Application* Solaris::CreateApplication()
{
    return new Playground();
}
