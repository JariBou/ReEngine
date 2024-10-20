#pragma once

#include <RealEngine/Core/Export.h>

namespace Re
{
	enum class RegistryType {
		Tickables,

	};

	class RE_CORE_API IRegistryItem
	{
		public:
			IRegistryItem(RegistryType registryType) : m_registryType(registryType) {};

			IRegistryItem(const IRegistryItem&) = delete;
			IRegistryItem(IRegistryItem&&) = delete;
			~IRegistryItem() = default;

			IRegistryItem& operator=(const IRegistryItem&) = delete;
			IRegistryItem& operator=(IRegistryItem&&) = delete;

		private:
			RegistryType m_registryType;
	};
}
