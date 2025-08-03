#pragma once
#include "Event.h"

namespace Core
{
	class TestEvent : public Event
	{
	public:
		EVENT_CLASS_CATEGORY(EventCategory::EventCategoryKeyboard);
		EVENT_CLASS_TYPE(KeyPressed);

		void LogInfo() const override
		{
			LOG_INFO("Logging from event");
		}
	};
}