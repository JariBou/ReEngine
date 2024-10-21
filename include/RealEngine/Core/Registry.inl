#include "Registry.h"
#pragma once

namespace Re
{
	template<Derived<IRegistryItem> T>
	inline void Registry<T>::Register(T* item)
	{
		m_items->push_back(item);
	}

	template<Derived<IRegistryItem> T>
	inline void Re::Registry<T>::Unregister(T* item)
	{
		auto it = m_items.begin();
		while (it != m_items.end()) {
			if (*item == *it) {
				m_items.erase(it);
				return;
			}
		}
	}
}
