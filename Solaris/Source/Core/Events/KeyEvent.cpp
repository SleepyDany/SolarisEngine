#include "slrpch.h"
#include "KeyEvent.h"

Solaris::KeyEvent::KeyEvent(int _code)
    : key_code(_code)
{
}

int Solaris::KeyEvent::get_key_code() const
{
    return key_code;
}

std::string Solaris::KeyEvent::to_string() const
{
    return Event::to_string() + " : " + std::to_string(key_code);
}

Solaris::KeyPressedEvent::KeyPressedEvent(int _code, int _count)
    : KeyEvent(_code)
    , repeat_count(_count)
{
}

int Solaris::KeyPressedEvent::get_repeat_count() const
{
    return repeat_count;
}

std::string Solaris::KeyPressedEvent::to_string() const
{
    return KeyEvent::to_string() + " | " + std::to_string(repeat_count);
}

Solaris::KeyReleasedEvent::KeyReleasedEvent(int _code)
    : KeyEvent(_code)
{
}
