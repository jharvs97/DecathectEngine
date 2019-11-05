#pragma once

#include "Decathect/Core.h"
#include "Window.h"

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
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};



	Application* CreateApp();
}

