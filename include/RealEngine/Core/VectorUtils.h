#pragma once

#include <vector>
#include <RealEngine/Core/Export.h>

namespace Re
{
	class RE_CORE_API VectorUtils
	{
		public:

			template <typename T>
			static void RemoveElement(std::vector<T>& vector, T element);
	};
}

#include <RealEngine/Core/VectorUtils.inl>
