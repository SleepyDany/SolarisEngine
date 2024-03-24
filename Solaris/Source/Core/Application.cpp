#include "slrpch.h"
#include "Application.h"

#include "Log.h"
#include "Events/ApplicationEvent.h"
#include "Events/MouseEvent.h"

namespace Solaris
{
    Application::Application()
    {
    }

    Application::~Application()
    {
    }

    void Application::exec()
    {
        WindowResizeEvent resize_event(1200, 720);
        MouseButtonPressedEvent btn_event(1);
        SLR_APP_LOG(Debug, "Current event is {}", resize_event.to_string());

        if (btn_event.is_in_category(ApplicationEvent))
        {
            SLR_APP_LOG(Debug, "Is app category");
        }

        if (btn_event.is_in_category(InputEvent))
        {
            SLR_APP_LOG(Debug, "Is input category");
        }

        if (btn_event.is_in_category(MouseEvent))
        {
            SLR_APP_LOG(Debug, "Is mouse category");
        }

        if (btn_event.is_in_category(MouseBtnEvent))
        {
            SLR_APP_LOG(Debug, "Is mouse btn category");
        }
        
        while(true);
    }
}
