#pragma once

#include "Decathect/Input.h"

namespace Decathect {
	class WindowsInput : public Input {
		
	protected:
		virtual bool IsKeyPressedImpl(int key);
	};
}