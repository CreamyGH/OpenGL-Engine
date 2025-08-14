#pragma once
#include "../pch.h"

#include "Event.h"
#include "../Helpers/Singleton.h"


namespace Core
{
    #define PUBLISH_EVENT(event) EventManager::get().PublishEvent(event)
    #define EVENT_LOG_CATEGORY(mask) EventManager::get().SetLoggingCategoryMask(mask)
    #define BIND_EVENT_FN(fn) [this](auto& ev) -> bool { return this->fn(ev); }

    using EventCallbackFn = std::function<bool(Event&)>;

    class EventManager : public Singleton<EventManager>
    {
        friend class Singleton<EventManager>;

    public:
        void SetLoggingCategoryMask(EventCategoryMask categoryMask) { 
            m_LoggingCategoryMask = categoryMask; 
        }

        void PublishEvent(Event& event)
        {
            EventTypeID eventType = event.GetType();
            LogEvent(event);

            if (event.Handled) 
                return;

            auto it = m_Listeners.find(eventType);
            if (it != m_Listeners.end()) {
                for (auto& listener : it->second)
                {
                    if (event.Handled) break;
                    event.Handled = listener(event);
                }
            }
        }

        template<typename EventT, typename F>
        void AddListenerFunc(F&& func)
        {
            EventTypeID eventType = EventT::StaticType();
            auto& listeners = m_Listeners[eventType];

            listeners.emplace_back([h = std::forward<F>(func)](Event& e) -> bool 
            {
                auto& specific = static_cast<EventT&>(e);
                return h(specific); 
            });
        }

    private:
        void LogEvent(const Event& event) const
        {
            if (event.IsInCategory(m_LoggingCategoryMask) && m_LoggingCategoryMask != 0)
            {
                LOG_TRACE("[Event] {0} {1}", event.GetName(), event.LogInfo());
            }
        }

    private:
        EventCategoryMask m_LoggingCategoryMask = 0;
        std::unordered_map<EventTypeID, std::vector<EventCallbackFn>> m_Listeners;
    };
}
