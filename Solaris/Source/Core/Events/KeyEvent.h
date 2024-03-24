#pragma once

#include "Event.h"

namespace Solaris
{
    class SOLARIS_API KeyEvent : public Event
    {
    protected:
        KeyEvent(int _code);
        
    public:
        EVENT_CATEGORY_TYPE(KeyboardEvent | InputEvent)
        int get_key_code() const;
        std::string to_string() const override;
        
    protected:
        int key_code = 0;
    };

    class SOLARIS_API KeyPressedEvent : public KeyEvent
    {
    public:
        KeyPressedEvent(int _code, int _count);

        EVENT_CLASS_TYPE(KeyPressed)
        int get_repeat_count() const;
        std::string to_string() const override;

    private:
        int repeat_count = 0;
    };
    
    class SOLARIS_API KeyReleasedEvent : public KeyEvent
    {
    public:
        KeyReleasedEvent(int _code);
        
        EVENT_CLASS_TYPE(KeyReleased)
    };
}

