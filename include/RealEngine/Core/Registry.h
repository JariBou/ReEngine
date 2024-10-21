#pragma once

#include <RealEngine/Core/Export.h>
#include <vector>

namespace Re
{
	template<typename T>
	concept C_RegistryItem = requires(T a)
	{
		{ std::hash<T>{}(a) } -> std::convertible_to<std::size_t>;
	};

	template<C_RegistryItem T>
	class RE_CORE_API Registry
	{
		public:
			Registry() = default;
			Registry(const Registry&) = delete;
			Registry(Registry&&) = delete;
			~Registry() = default;

			Registry& operator=(const Registry&) = delete;
			Registry& operator=(Registry&&) = delete;

		private:
	};
}

#include <RealEngine/Core/Registry.inl>
