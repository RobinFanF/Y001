#pragma once


#include "..\core.h"

namespace hezzle
{
	enum class EventType
	{
		None = 0, 
		WindowClose,WindowResize,WindowFocus,WindowMoved,
		AppTick,AppUpdata,AppRender,
		KeyPressed,KeyReleased,
		MouseButtonPressed, MouseButtonReleased,MouseMoved,MouseScrolled
	};

	enum EventCategory
	{
		None = 0,
		EventCategoryApplication = BIT(1),
		EventCategoryInput = BIT(2),
		EventCategoryKeyboard = BIT(3),
		EventCategoryMouse = BIT(4),
		EventCategoryMousebutton = BIT(5),
	};

//第二个GeteVENTTYPE()的考虑是：使用一个基类的指针来取得事件类型
#define EVENT_CLASS_TYPE(type) static EventType GetStaticType(){ return EventType::type;}\
																virtual EventType GetEventType() const override {return GetStaticType();}\
																virtual const char* GetName() const override {return #type;}

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	class HEZZLE_API Event
	{
	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}

		bool m_Handled = false;
	};

	//TODO
	class EventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool (T&)>;
	public:
		EventDispatcher(Event& event) 
			: m_Event(event){}
	
		template<typename T>
		bool Dispatch(EventFn<T> func)
		{
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.m_Handled = func(*(T*)&m_Event);
				return true;
			}

			return false;
		}

	
	private:
		Event& m_Event;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}

}