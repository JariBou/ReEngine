#pragma once

#include <vector>
#include <RealEngine/Core/Export.h>

#include "RealEngine/Core/ObjectHandling/RePtr.h"

namespace Re
{
	class ReObject;

	class RE_CORE_API QuadtreeNode : public ReHandledObject<QuadtreeNode>
	{
		public:
			QuadtreeNode();
			QuadtreeNode(const QuadtreeNode& other);
			QuadtreeNode(QuadtreeNode&&) = delete;
			~QuadtreeNode() override = default;
		
			QuadtreeNode& operator=(const QuadtreeNode& other);
			QuadtreeNode& operator=(QuadtreeNode&& other) noexcept;

		private:
			// Actually should be a physics comp but we don't have one yet
			std::vector<RePtr<ReObject>> m_childrenObjects;
			// std::shared_ptr because we want to easily copy another tree
			std::vector<std::shared_ptr<QuadtreeNode>> m_childrenNodes;
	};
}


