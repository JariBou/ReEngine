#pragma once

#include <RealEngine/Core/Export.h>
#include <vector>

namespace Re
{
	class IRegistryItem;

	template<class T, class U>
	concept Derived = std::is_base_of<U, T>::value;

	template<Derived<IRegistryItem> T = IRegistryItem>
	class RE_CORE_API Registry
	{
		public:
			Registry() = default;
			Registry(const Registry&) = delete;
			Registry(Registry&&) = delete;
			~Registry() = default;

			Registry& operator=(const Registry&) = delete;
			Registry& operator=(Registry&&) = delete;

			void Register(T* item);
			void Unregister(T* item);

		private:
			std::vector<T> m_items;
	};

	class IRegistryItem {
	public:

		void OnRegistered(Registry<>* registry) {
			m_registry = registry;
		}

		~IRegistryItem() {
			if (m_registry != nullptr) m_registry->Unregister(this);
		}


	private:
		Registry<>* m_registry = nullptr;
	};
	
}

#include <RealEngine/Core/Registry.inl>
