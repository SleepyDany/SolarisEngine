#pragma once

#include "Core/Core.h"

namespace Solaris
{
    // This events system is blocking
    // TODO: buffer events in events bus?
    
    enum class EEventType
    {
        None = 0,
        
        WindowClosed,
        WindowResize,
        WindowFocus,
        WindowLostFocus,
        WindowMoved,

        AppTick,
        AppUpdate,
        AppRender,

        KeyPressed,
        KeyReleased,

        MouseBtnPressed,
        MouseBtnReleased,
        MouseMoved,
        MouseScrolled
    };

    enum EEventCategory
    {
        None = 0,
        ApplicationEvent = BIT(0),
        InputEvent       = BIT(1),
        KeyboardEvent    = BIT(2),
        MouseEvent       = BIT(3),
        MouseBtnEvent    = BIT(4)
    };

#define EVENT_CLASS_TYPE(type) \
    static EEventType get_static_type() { return EEventType::##type; } \
    virtual EEventType get_event_type() const override { return get_static_type(); } \
    virtual const char* get_name() const override { return #type; } \

#define EVENT_CATEGORY_TYPE(category) \
    virtual int get_category_flags() const override { return category; } \
    
    class SOLARIS_API Event
    {
        friend class EventDispatcher;
        
    public:
        virtual ~Event() = default;
        
        virtual EEventType get_event_type() const = 0;
        virtual int get_category_flags() const = 0;
        virtual const char* get_name() const = 0;
        virtual std::string to_string() const;
        
        bool is_in_category(EEventCategory _category) const;

    private:
        bool b_is_handled = false;
    };

    class SOLARIS_API EventDispatcher
    {
        template<class T>
        using EventFunc = std::function<bool(T&)>;

    public:
        EventDispatcher(Event& _event);
        
        template<class T>
        bool dispatch(EventFunc<T> _func)
        {
            if (event.get_event_type() == T::get_static_type())
            {
                event.b_is_handled = _func(*static_cast<T*>(&event));
                return true;
            }
            return false;
        }

    private:
        Event& event;
    };

    inline std::ostream& operator<<(std::ostream& _stream, const Event& _event)
    {
        return _stream << _event.to_string();
    }
}
