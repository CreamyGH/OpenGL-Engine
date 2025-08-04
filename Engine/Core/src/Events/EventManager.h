#pragma once
#include "Event.h"
#include "../Helpers/Singleton.h"

namespace Core
{
#define PUBLISH_EVENT(event) EventManager::get().PublishEvent(event)
#define EVENT_LOG_CATEGORY(category) EventManager::get().SetLoggingCategoryMask(category)
#define BIND_EVENT_FN(fn) [this](auto& ev) -> bool { return this->fn(ev); }

	using EventCallbackFn = std::function<bool(Event&)>;

	class EventManager : public Singleton<EventManager>
	{
	friend class Singleton<EventManager>;

	public:
		void SetLoggingCategoryMask(int CategoryMask) { m_LoggingCategoryMask = CategoryMask; }

		void PublishEvent(Event& event)
		{
			int eventType = static_cast<int>(event.GetEventType());

			LogEvent(event);
			if (event.Handled) return;

			for (auto& listener : m_Listeners[eventType])
			{
				if (event.Handled) break;
				event.Handled = listener(event);
			}
		}

		template<typename EventT, typename F>
		void AddListenerFunc(F&& func)
		{
			int eventType = static_cast<int>(EventT::GetStaticType());
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
			if (event.IsInCategory(m_LoggingCategoryMask) 
				&& !event.IsInCategory(EventCategory::None))
			{
				LOG_TRACE("[Event] {0} {1}", event.GetName(), event.LogInfo());
			}
		}

	private:
		int m_LoggingCategoryMask = 0;
		std::unordered_map<int, std::vector<EventCallbackFn>> m_Listeners;
	};
}