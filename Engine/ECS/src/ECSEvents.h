#pragma once

#include "Events/Event.h"

using namespace Core;

namespace ECS
{
    namespace EventTypes
    {
        constexpr EventTypeID ComponentAdded    =  9;
        constexpr EventTypeID ComponentModified = 10;
        constexpr EventTypeID ComponentRemoved  = 11;
    }

    namespace EventCategories
    {
        constexpr EventCategoryMask Component = 1 << 4;
    }
}
