#pragma once

#include <RealEngine/Core/Export.h>

namespace Re
{
	template<class T>
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

		private:
			std::vector<T> items;

	};

	template<class T>
	inline void Registry<T>::Register(T* pItem)
	{
		items.push_back(pItem);
	}

}
