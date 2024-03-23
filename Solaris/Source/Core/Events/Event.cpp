#include "slrpch.h"
#include "Event.h"

std::string Solaris::Event::to_string() const
{
    return get_name();
}

bool Solaris::Event::is_in_category(EEventCategory category) const
{
    return get_category_flags() & category;
}

Solaris::EventDispatcher::EventDispatcher(Event& cur_event)
    : event(cur_event)
{
}
