#pragma once

#include <memory>
#include <RealEngine/Core/Export.h>

namespace Re
{
	class RE_CORE_API RePtrData
	{
		public:
			void* object;

		static std::shared_ptr<RePtrData> GetEmptyObject();
	};
}


