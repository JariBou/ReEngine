#pragma once

#include <RealEngine/Core/Export.h>
#include <vector>

namespace Re
{
	class IRegistryItem;
	
	template<class T=IRegistryItem>
	class RE_CORE_API Registry
	{
		public:
			Registry() = default;
			Registry(const Registry&) = delete;
			Registry(Registry&&) = delete;
			~Registry() = default;

			Registry& operator=(const Registry&) = delete;
			Registry& operator=(Registry&&) = delete;

			void Register(T* pItem);
		
			void Unregister(IRegistryItem* registryItem);

		private:
			std::vector<T> items;
	};

	enum class RegistryType {
		Tickables,

	};
	
	class RE_CORE_API IRegistryItem
	{
	public:
		IRegistryItem(RegistryType registryType) : m_registryType(registryType) {}

		IRegistryItem(const IRegistryItem& old) {
			m_registryType = old.m_registryType;
			m_registry = old.m_registry;
		}
		IRegistryItem(IRegistryItem&& old) = delete;

		~IRegistryItem()
		{
			if (m_registry != nullptr) m_registry->Unregister(this);
		}

		//IRegistryItem& operator=(const IRegistryItem&) = delete;
		IRegistryItem& operator=(IRegistryItem&& old){
			m_registryType = old.m_registryType;
			m_registry = old.m_registry;
			return *this;
		}

		bool operator==(IRegistryItem other) { return true; }

		void OnRegister(Registry<>* registry)
		{
			m_registry = registry;
		}

	private:
		RegistryType m_registryType;
		Registry<>* m_registry = nullptr;
	};

}

#include "Registry.inl"
