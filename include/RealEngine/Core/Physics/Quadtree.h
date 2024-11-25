#pragma once

#include <vector>
#include <RealEngine/Core/Export.h>

#include "QuadtreeNode.h"

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

			void Rebuild();
			void RebuildAsync();

			Quadtree& operator=(const Quadtree&) = delete;
			Quadtree& operator=(Quadtree&&) = delete;

		private:
			QuadtreeNode root;
			std::thread m_rebuild_thread;

			bool m_wants_to_rebuild;
			bool m_is_rebuilding;
	};
}


