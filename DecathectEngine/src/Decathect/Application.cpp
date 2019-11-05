#include "dcthctpch.h"
#include "Application.h"
#include "Decathect/Log.h"



// REMOVE LATER
#include <GLFW/glfw3.h>

namespace Decathect {

#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1) // Learn about std::bind

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));
	}
	Application::~Application()
	{

	}

	void Application::OnEvent(Event& e)
	{
		DCTHCT_CORE_INFO("{0}", e);
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