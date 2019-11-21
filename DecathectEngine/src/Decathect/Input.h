// Mouse input

#pragma once

#include "Decathect/Core.h"

namespace Decathect {

	// Singleton interface, implement for each platform
	class DCTHCT_API Input
	{
	public:
		static bool IsKeyPressed(int key) { m_Instance->IsKeyPressedImpl(key); }

	protected:
		virtual bool IsKeyPressedImpl(int key) = 0;
	private:
		static Input* m_Instance;
	};
}


