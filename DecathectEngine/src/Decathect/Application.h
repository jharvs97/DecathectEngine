#pragma once

#include "Core.h"

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

