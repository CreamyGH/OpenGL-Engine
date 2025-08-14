#pragma once

#include "Event.h"
#include "CoreEvents.h"

namespace Core 
{
	class KeyEvent : public Event
	{
	public:
		KeyEvent() = default;
		inline int GetKeyCode() const { return m_KeyCode; }

		EVENT_CLASS_CATEGORY(EventCategories::Keyboard)

	protected:
		KeyEvent(int keycode) : m_KeyCode(keycode) {}
		int m_KeyCode = 0;
	};

	class KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keycode, int repeatCount)
			: KeyEvent(keycode), m_RepeatCount(repeatCount) {
		}

		inline int GetRepeatCount() const { return m_RepeatCount; }

		std::string LogInfo() const override
		{
			std::stringstream ss;
			ss << "Keycode: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(EventTypes::KeyPressed, "KeyPressed")
	private:
		int m_RepeatCount;
	};

	class KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keycode)
			: KeyEvent(keycode) {
		}

		std::string LogInfo() const override
		{
			std::stringstream ss;
			ss << "Keycode: " << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(EventTypes::KeyReleased, "KeyReleased")
	};

	class KeyTypedEvent : public KeyEvent
	{
	public:
		KeyTypedEvent(int keycode)
			: KeyEvent(keycode) {
		}

		std::string LogInfo() const override
		{
			std::stringstream ss;
			ss << "Keycode: " << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(EventTypes::KeyTyped, "KeyTyped")
	};
}