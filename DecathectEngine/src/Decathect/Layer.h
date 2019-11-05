#pragma once

#include "Decathect/Core.h"
#include "Decathect/Events/Event.h"

namespace Decathect {

	class DCTHCT_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		// Override these when making your own layer

		virtual void OnAttach() {} // Pushed onto Layer stack
		virtual void OnDetach() {} // Popped off layer stack
		virtual void OnUpdate() {} // Called by application every frame
		virtual void OnEvent(Event& event) {} // When event sent to layer

		inline const std::string& GetName() const { return m_DebugName; }
	protected:
		std::string m_DebugName; // Name for debugging only
		bool m_Enabled; // For future reference, allow to enable layers
	};
}