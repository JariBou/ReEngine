#pragma once

#include <RealEngine/Core/Export.h>
#include <memory>

namespace Re
{
	struct RE_CORE_API ReHandleData
	{
		void* object;

		static std::shared_ptr<ReHandleData> GetEmptyObject();
	};
}
