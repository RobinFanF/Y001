#pragma once

#include "Event.h"


namespace hezzle
{
	class HEZZLE_API KeyEvent : public Event
	{
	public:
		int GetKeyCode() const { return m_KeyCode; }

		
		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	
	protected:
		KeyEvent(const int keycode)
			: m_KeyCode(keycode) {}

		int m_KeyCode;
	};

	class HEZZLE_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent( int keycode, int repeateCount = false)
			: KeyEvent(keycode), m_repeateCount(repeateCount) {}

		inline int GetRepeateCount() const { return m_repeateCount; }
		//inline int IsRepeat() const { return m_IsRepeat; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_KeyCode << " (repeat = " << m_repeateCount << ")";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)
	private:
		int 	m_repeateCount;
	};

	class HEZZLE_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keycode)
			: KeyEvent(keycode){}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};



}