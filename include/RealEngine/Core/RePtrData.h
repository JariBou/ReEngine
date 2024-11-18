#pragma once

#include <RealEngine/Core/Export.h>
#include <memory>

namespace Re
{
	class RE_CORE_API RePtrData
	{
		public:
			void* object;

			static std::shared_ptr<RePtrData> GetEmptyObject();
	};
}


