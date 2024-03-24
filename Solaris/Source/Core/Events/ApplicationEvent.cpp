#include "slrpch.h"

#include "ApplicationEvent.h"

/* Window Resize Event */

Solaris::WindowResizeEvent::WindowResizeEvent(uint32_t _width, uint32_t _height)
    : width(_width)
    , height(_height)
{
}

uint32_t Solaris::WindowResizeEvent::get_width() const
{
    return width;
}

uint32_t Solaris::WindowResizeEvent::get_height() const
{
    return height;
}

std::string Solaris::WindowResizeEvent::to_string() const
{
    return Event::to_string() + " : (" + std::to_string(width) + " ; " + std::to_string(height) + ")";
}
