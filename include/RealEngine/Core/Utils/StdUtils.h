#pragma once

#include <vector>
#include <RealEngine/Core/Export.h>

namespace Re
{
	class RE_CORE_API ArrayUtils
	{
		public:

			template <typename T>
			static void RemoveElement(std::vector<T>& vector, T element);
	};

	class RE_CORE_API MapUtils
	{
	public:

		template <typename T, typename U>
		static void RemoveElementByKey(std::map<T, U>& map, T element);
	};
}

#include <RealEngine/Core/Utils/StdUtils.inl>
