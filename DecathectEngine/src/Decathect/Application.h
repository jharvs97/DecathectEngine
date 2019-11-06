#pragma once

#include "Decathect/Core.h"

#include "Decathect/Window.h"
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


		inline static Application& Instance() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	private:
		static Application* s_Instance;
	};


	// Defined by client
	Application* CreateApp();
}

