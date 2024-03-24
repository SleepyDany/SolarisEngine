#include "Solaris.h"

class Playground : public Solaris::Application
{
public:
    Playground() = default;
    ~Playground() = default;
};

Solaris::Application* Solaris::create_application()
{
    return new Playground();
}
