#pragma once

#include "ECSEvents.h"
#include <entt/entt.hpp>

namespace ECS
{
    class ComponentEvent : public Event
    {
    public:
        ComponentEvent(entt::entity entity) : m_Entity(entity) {}

        inline entt::entity GetEntity() const { return m_Entity; }

        EVENT_CLASS_CATEGORY(EventCategories::Component);

    protected:
        entt::entity m_Entity;
    };

    class ComponentAddedEvent : public ComponentEvent
    {
    public:
        ComponentAddedEvent(entt::entity entity) : ComponentEvent(entity) {}

        EVENT_CLASS_TYPE(EventTypes::ComponentAdded, "ComponentAdded");
    };

    class ComponentModifiedEvent : public ComponentEvent
    {
    public:
        ComponentModifiedEvent(entt::entity entity) : ComponentEvent(entity) {}

        EVENT_CLASS_TYPE(EventTypes::ComponentModified, "ComponentModified");
    };

    class ComponentRemovedEvent : public ComponentEvent
    {
    public:
        ComponentRemovedEvent(entt::entity entity) : ComponentEvent(entity) {}

        EVENT_CLASS_TYPE(EventTypes::ComponentRemoved, "ComponentRemoved");
    };
}