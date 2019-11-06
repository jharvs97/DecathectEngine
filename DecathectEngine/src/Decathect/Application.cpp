#include "dcthctpch.h"
#include "Application.h"
#include "Decathect/Log.h"

#include <glad/glad.h>

namespace Decathect {

	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		DCTHCT_CORE_ASSERT(!s_Instance, "Application already exists!");
		s_Instance = this;

		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(DCTHCT_BIND_EVENT_FN(Application::OnEvent));
	}

	Application::~Application()
	{

	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
	}

	void Application::PushOverlay(Layer* layer)
	{
		m_LayerStack.PushOverlay(layer);
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(DCTHCT_BIND_EVENT_FN(Application::OnWindowClose));

		//DCTHCT_CORE_TRACE("Application Event: {0}", e);

		// Iterate backwards through the Layer Stack
		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin(); )
		{
			(*--it)->OnEvent(e);
			if (e.Handled)
				break;
		}
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
			glClearColor(255.0f / 255.0f, 119.0f / 255.0f, 56.0f / 255.0f, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* layer : m_LayerStack)
				layer->OnUpdate();

			m_Window->OnUpdate();
		}
	}
}