#include "dcthctpch.h"
#include "LayerStack.h"

namespace Decathect {

	LayerStack::LayerStack()
	{
		m_LayerHeadOffset = 0;
	}

	LayerStack::~LayerStack()
	{
		for (Layer* l : m_Layers)
			delete l;
	}

	void LayerStack::PushLayer(Layer* layer)
	{
		m_Layers.emplace(m_Layers.begin() + m_LayerHeadOffset, layer);
		m_LayerHeadOffset++;
	}

	void LayerStack::PushOverlay(Layer* overlay)
	{
		m_Layers.emplace_back(overlay);
	}

	void LayerStack::PopLayer(Layer* layer)
	{
		// Find the current layer from the beginning of the vec
		// To the current head of the "Layer stack"
		auto it = std::find(m_Layers.begin(), m_Layers.begin() + m_LayerHeadOffset, layer);

		if (it != m_Layers.begin() + m_LayerHeadOffset)
		{
			m_Layers.erase(it);
			m_LayerHeadOffset--;
		}

	}

	void LayerStack::PopOverlay(Layer* layer)
	{
		// Find the current overlay from the beginning of the
		// "Overlay stack" that sits upon the layer stack
		auto it = std::find(m_Layers.begin() + m_LayerHeadOffset, m_Layers.end(), layer);

		if (it != m_Layers.end())
		{
			m_Layers.erase(it);
		}

	}
}