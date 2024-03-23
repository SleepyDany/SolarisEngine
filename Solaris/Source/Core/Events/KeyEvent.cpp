#include "slrpch.h"
#include "KeyEvent.h"

Solaris::KeyEvent::KeyEvent(int code)
    : key_code(code)
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

Solaris::KeyPressedEvent::KeyPressedEvent(int code, int count)
    : KeyEvent(code)
    , repeat_count(count)
{
}

int Solaris::KeyPressedEvent::get_repeat_count() const
{
    return repeat_count;
}

std::string Solaris::KeyPressedEvent::to_string() const
{
    return KeyEvent::to_string() + " / " + std::to_string(repeat_count);
}

Solaris::KeyReleasedEvent::KeyReleasedEvent(int code)
    : KeyEvent(code)
{
}
