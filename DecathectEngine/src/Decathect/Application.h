#pragma once

#include "Core.h"

#include "Window.h"
#include "Decathect/LayerStack.h"
#include "Decathect/Events/Event.h"
#include "Decathect/Events/ApplicationEvent.h"


namespace Decathect {
	class DCTHCT_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};


	// Defined by client
	Application* CreateApp();
}

