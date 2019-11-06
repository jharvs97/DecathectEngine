#pragma once

#include "Decathect/Core.h"

#include "Decathect/Layer.h"
#include "Decathect/Events/MouseEvent.h"
#include "Decathect/Events/KeyEvent.h"
#include "Decathect/Events/ApplicationEvent.h"


namespace Decathect {

	class DCTHCT_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach(); 
		virtual void OnDetach(); 
		virtual void OnUpdate(); 
		virtual void OnEvent(Event& event);

		
	private:
		// ImGui Event Callbacks
		bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
		bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
		bool OnMouseMovedEvent(MouseMovedEvent& e);
		bool OnMouseScrolledEvent(MouseScrolledEvent& e);
		bool OnWindowResizeEvent(WindowResizeEvent& e);
		bool OnKeyTypedEvent(KeyTypedEvent& e);
		bool OnKeyReleasedEvent(KeyReleasedEvent& e);
		bool OnKeyPressedEvent(KeyPressedEvent& e);

	private:
		float m_Time;
	};

}