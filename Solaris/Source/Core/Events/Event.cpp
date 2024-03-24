#include "slrpch.h"
#include "Event.h"

std::string Solaris::Event::to_string() const
{
    return get_name();
}

bool Solaris::Event::is_in_category(EEventCategory _category) const
{
    return get_category_flags() & _category;
}

Solaris::EventDispatcher::EventDispatcher(Event& _event)
    : event(_event)
{
}
