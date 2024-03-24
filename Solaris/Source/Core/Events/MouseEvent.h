#pragma once

#include "Event.h"

namespace Solaris
{
    class SOLARIS_API MouseMoveEvent : public Event
    {
    public:
        MouseMoveEvent(float _x, float _y);
        EVENT_CLASS_TYPE(MouseMoved)
        EVENT_CATEGORY_TYPE(MouseEvent | InputEvent)

        float get_x() const;
        float get_y() const;
        std::string to_string() const override;

    private:
        float x = 0.0f;
        float y = 0.0f;
    };

    class SOLARIS_API MouseScrolledEvent : public Event
    {
    public:
        MouseScrolledEvent(float _x_offset, float _y_offset);
        EVENT_CLASS_TYPE(MouseScrolled)
        EVENT_CATEGORY_TYPE(MouseEvent | InputEvent)

        float get_x_offset() const;
        float get_y_offset() const;
        std::string to_string() const override;

    private:
        float x_offset = 0.0f;
        float y_offset = 0.0f;
    };

    class SOLARIS_API MouseButtonEvent : public Event
    {
    public:
        EVENT_CATEGORY_TYPE(MouseBtnEvent | MouseEvent | InputEvent)

        int get_button() const;

    protected:
        MouseButtonEvent(int _button);

    private:
        int button;
    };
    
    class SOLARIS_API MouseButtonPressedEvent : public MouseButtonEvent
    {
    public:
        MouseButtonPressedEvent(int _button);
        EVENT_CLASS_TYPE(MouseBtnPressed)

        std::string to_string() const override;
    };

    class SOLARIS_API MouseButtonReleasedEvent : public MouseButtonEvent
    {
    public:
        MouseButtonReleasedEvent(int _button);
        EVENT_CLASS_TYPE(MouseBtnReleased)

        std::string to_string() const override;
    };
}
