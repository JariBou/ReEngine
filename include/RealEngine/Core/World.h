#pragma once

#include <RealEngine/Core/Export.h>
#include <vector>

namespace Re
{
	class ReObject;

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
			std::vector<ReObject*> m_objects;
	};
}

#include <RealEngine/Core/World.inl>
