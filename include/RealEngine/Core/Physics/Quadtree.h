#pragma once

#include <vector>
#include <RealEngine/Core/Export.h>

namespace Re
{
	class ReObject;

	class RE_CORE_API Quadtree
	{
		public:
			Quadtree() = default;
			Quadtree(const Quadtree&) = delete;
			Quadtree(Quadtree&&) = delete;
			~Quadtree() = default;

			Quadtree& operator=(const Quadtree&) = delete;
			Quadtree& operator=(Quadtree&&) = delete;

		private:
	};
}


