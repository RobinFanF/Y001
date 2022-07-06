#pragma once

#include "hezzle/Layer.h"
#include "hezzle/Events/KeyEvent.h"
#include "hezzle/Events/ApplicationEvent.h"
#include "hezzle/Events/MouseEvent.h"


namespace hezzle
{
	class HEZZLE_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiDraw() override;

		void Begin();
		void End();
	private:
		float m_Time = 0.0f;
	};
}