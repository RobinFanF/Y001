#pragma once

#include "hezzle/core.h"
#include "hezzle/Events/Event.h"


namespace hezzle
{
	class HEZZLE_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach(){}
		virtual void OnUpdate() {}
		virtual void OnEvent(Event& event){}
		virtual void OnImGuiDraw() {}

		inline const std::string& GetName() const { return m_DebugName; }

	private:
		std::string m_DebugName;
	};

}