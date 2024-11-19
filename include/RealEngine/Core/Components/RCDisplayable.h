#pragma once

#include <RealEngine/Core/Export.h>

namespace Re
{
	class RE_CORE_API RCDisplayable
	{
		public:
			RCDisplayable() = default;
			RCDisplayable(const RCDisplayable&) = delete;
			RCDisplayable(RCDisplayable&&) = delete;
			~RCDisplayable() = default;

			RCDisplayable& operator=(const RCDisplayable&) = delete;
			RCDisplayable& operator=(RCDisplayable&&) = delete;

		private:
	};
}


