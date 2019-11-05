#include "dcthctpch.h"
#include "Application.h"

#include "Decathect/Events/ApplicationEvent.h"
#include "Decathect/Log.h"

namespace Decathect {
	Application::Application()
	{
	}
	Application::~Application()
	{
	}
	void Application::Run()
	{
		// Testing the Window Resize event
		// WindowResizeEvent e(600, 800);
		// DCTHCT_TRACE(e);

		while (true);
	}
}