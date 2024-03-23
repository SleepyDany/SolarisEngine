#pragma once

#include "Event.h"

namespace Solaris
{
    class KeyEvent : public Event
    {
    protected:
        KeyEvent(int code);
        
    public:
        EVENT_CATEGORY_TYPE(KeyboardEvent | InputEvent)
        int get_key_code() const;
        std::string to_string() const override;
        
    protected:
        int key_code = 0;
    };

    class KeyPressedEvent : public KeyEvent
    {
    public:
        KeyPressedEvent(int code, int count);

        EVENT_CLASS_TYPE(KeyPressed)
        int get_repeat_count() const;
        std::string to_string() const override;

    private:
        int repeat_count = 0;
    };
    
    class KeyReleasedEvent : public KeyEvent
    {
    public:
        KeyReleasedEvent(int code);
        
        EVENT_CLASS_TYPE(KeyReleased)
    };
}

