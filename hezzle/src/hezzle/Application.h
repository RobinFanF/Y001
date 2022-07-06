#pragma once
#include "core.h"
#include "Window.h"
#include "hezzle/LayerStack.h"
#include "Events/ApplicationEvent.h"

namespace hezzle
{	 
	class HEZZLE_API Application
	{
	public:
		Application();
	virtual	~Application();

		void Run();

		void OnEvent(Event& e);
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }

	private:
		bool OnWindowClose(WindowCloseEvent& e);
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;

		static Application* s_Instance;

	};
	
	Application* CreateApplication();

}
