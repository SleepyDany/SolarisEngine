#include "slrpch.h"
#include "MouseEvent.h"

/* Mouse Move Event */

Solaris::MouseMoveEvent::MouseMoveEvent(float _x, float _y)
    : x(_x)
    , y(_y)
{
}

float Solaris::MouseMoveEvent::get_x() const
{
    return x;
}

float Solaris::MouseMoveEvent::get_y() const
{
    return y;
}

std::string Solaris::MouseMoveEvent::to_string() const
{
    return Event::to_string() + "(" + std::to_string(x) +  " ; " + std::to_string(y) + ")";
}

/* Mouse Scrolled Event*/

Solaris::MouseScrolledEvent::MouseScrolledEvent(float _x_offset, float _y_offset)
    : x_offset(_x_offset)
    , y_offset(_y_offset)
{
}

float Solaris::MouseScrolledEvent::get_x_offset() const
{
    return x_offset;
}

float Solaris::MouseScrolledEvent::get_y_offset() const
{
    return y_offset;
}

std::string Solaris::MouseScrolledEvent::to_string() const
{
    return Event::to_string() + "(" + std::to_string(x_offset) + " ; " + std::to_string(y_offset) + ")";
}

/* Mouse Button Event */

int Solaris::MouseButtonEvent::get_button() const
{
    return button;
}

Solaris::MouseButtonEvent::MouseButtonEvent(int _button)
    : button(_button)
{
}

/* Mouse Button Pressed Event */

Solaris::MouseButtonPressedEvent::MouseButtonPressedEvent(int _button)
    : MouseButtonEvent(_button)
{
}

std::string Solaris::MouseButtonPressedEvent::to_string() const
{
    return MouseButtonEvent::to_string() + " : " + std::to_string(get_button());
}

/* Mouse Button Released Event */
 
Solaris::MouseButtonReleasedEvent::MouseButtonReleasedEvent(int _button)
    : MouseButtonEvent(_button)
{
}

std::string Solaris::MouseButtonReleasedEvent::to_string() const
{
    return MouseButtonEvent::to_string() + " : " + std::to_string(get_button());
}
