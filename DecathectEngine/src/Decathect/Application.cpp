#include "dcthctpch.h"
#include "Application.h"
#include "Decathect/Log.h"

// REMOVE LATER
#include <GLFW/glfw3.h>

namespace Decathect {

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1) // Learn about std::bind

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}
	Application::~Application()
	{

	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);

		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

		DCTHCT_CORE_TRACE("{0}", e);
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}

	void Application::Run()
	{
		while (m_Running)
		{
			/* Testing GL Window REMOVE LATER */
			glClearColor(1, 0, 0, 1); // Red 
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}
}