#pragma once

#include <vector>
#include <RealEngine/Core/Export.h>

#include "RealEngine/Core/ObjectHandling/RePtr.h"

namespace Re
{
	class ReObject;

	class RE_CORE_API QuadtreeNode
	{
		public:
			QuadtreeNode() = default;
			QuadtreeNode(const QuadtreeNode&) = delete;
			QuadtreeNode(QuadtreeNode&&) = delete;
			~QuadtreeNode() = default;

			QuadtreeNode& operator=(const QuadtreeNode&) = delete;
			QuadtreeNode& operator=(QuadtreeNode&&) = delete;

		private:
			// Actually should be a physics comp but we don't have one yet 
			std::vector<RePtr<ReObject>> childrenObjects;
			std::vector<QuadtreeNode> childrenNodes;
	};
}


