#pragma once
#include "../pch.h"

namespace Core
{
	enum class EventType
	{
		None = 0,
		KeyPressed, KeyReleased, KeyTyped,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventCategory
	{
		None = 0,
		EventCategoryWindow =      (1 << 0),
		EventCategoryKeyboard =    (1 << 1),
		EventCategoryMouse =       (1 << 2),
		EventCategoryMouseButton = (1 << 3)
	};

	#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

	#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	class Event
	{
	public:
		bool Handled = false;

		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual const std::string LogInfo() const = 0;

		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}

		inline bool IsInCategory(int categoryMask) const
		{
			return (GetCategoryFlags() & categoryMask) != 0;
		}
	};
}