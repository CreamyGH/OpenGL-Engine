#pragma once
#include "Event.h"

namespace Core
{
    namespace EventTypes
    {
        constexpr EventTypeID WindowResized       = 0;
        constexpr EventTypeID WindowClosed        = 1;
    
        constexpr EventTypeID KeyPressed          = 2;
        constexpr EventTypeID KeyReleased         = 3;
        constexpr EventTypeID KeyTyped            = 4;
    
    
        constexpr EventTypeID MouseButtonPressed  = 5;
        constexpr EventTypeID MouseButtonReleased = 6;
        constexpr EventTypeID MouseMoved          = 7;
        constexpr EventTypeID MouseScrolled       = 8;
    }
    
    namespace EventCategories
    {
        constexpr EventCategoryMask Window      = 1 << 0;
        constexpr EventCategoryMask Keyboard    = 1 << 1;
        constexpr EventCategoryMask Mouse       = 1 << 2;
        constexpr EventCategoryMask MouseButton = 1 << 3;
    }
}
