#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Decathect {
	class DCTHCT_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};

	Application* CreateApp();
}

