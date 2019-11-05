#pragma once

/*
	TODO: Discuss the ownership of layers

	At the moment the LayerStack owns the Layers of the App.
	
	TODO: Look into using newer raw_ptr wrapper classes
*/

#include "Decathect/Core.h"
#include "Layer.h"

namespace Decathect {

	class DCTHCT_API LayerStack
	{
	public:
		LayerStack();
		~LayerStack();

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
		void PopLayer(Layer* layer);
		void PopOverlay(Layer* overlay);

		std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
		std::vector<Layer*>::iterator end() { return m_Layers.end(); }

	private:
		std::vector<Layer*> m_Layers;
		//std::vector<Layer*>::iterator m_LayerHead;
		unsigned int m_LayerHeadOffset;
	};
}