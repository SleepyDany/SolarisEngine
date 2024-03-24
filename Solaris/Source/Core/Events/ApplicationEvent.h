#pragma once
#include "Event.h"

namespace Solaris
{
    class SOLARIS_API WindowResizeEvent : public Event
    {
    public:
        WindowResizeEvent(uint32_t _width, uint32_t _height);
        EVENT_CLASS_TYPE(WindowResize)
        EVENT_CATEGORY_TYPE(ApplicationEvent)

        uint32_t get_width() const;
        uint32_t get_height() const;
        std::string to_string() const override;

    private:
        uint32_t width = 0;
        uint32_t height = 0;
    };

    class SOLARIS_API WindowCloseEvent : public Event
    {
    public:
        WindowCloseEvent() = default;
        EVENT_CLASS_TYPE(WindowClosed)
        EVENT_CATEGORY_TYPE(ApplicationEvent)
    };

    class SOLARIS_API ApplicationTickEvent : public Event
    {
    public:
        ApplicationTickEvent() = default;
        EVENT_CLASS_TYPE(AppTick)
        EVENT_CATEGORY_TYPE(ApplicationEvent)
    };

    class SOLARIS_API ApplicationUpdateEvent : public Event
    {
    public:
        ApplicationUpdateEvent() = default;
        EVENT_CLASS_TYPE(AppUpdate)
        EVENT_CATEGORY_TYPE(ApplicationEvent)
    };

    class SOLARIS_API ApplicationRenderEvent : public Event
    {
    public:
        ApplicationRenderEvent() = default;
        EVENT_CLASS_TYPE(AppRender)
        EVENT_CATEGORY_TYPE(ApplicationEvent)
    };
}
