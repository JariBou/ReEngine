#pragma once

#include <RealEngine/Core/Export.h>

namespace Re
{
	class RE_CORE_API World
	{
		public:
			World() = default;
			World(const World&) = delete;
			World(World&&) = delete;
			~World() = default;

			World& operator=(const World&) = delete;
			World& operator=(World&&) = delete;

		private:
	};
}


