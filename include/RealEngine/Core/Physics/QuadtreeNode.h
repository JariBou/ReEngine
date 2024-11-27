#pragma once

#include <vector>
#include <RealEngine/Core/Export.h>
#include <RealEngine/Core/ReObject.h>

#include "RealEngine/Core/ObjectHandling/RePtr.h"

namespace Re
{
	// class ReObject;

	class RE_CORE_API QuadtreeNode : public ReHandledObject<QuadtreeNode>
	{
		public:
			QuadtreeNode();
			explicit QuadtreeNode(uint8_t maxObjectsPerNode);
			QuadtreeNode(const QuadtreeNode& other);
			QuadtreeNode(QuadtreeNode&& other) noexcept;
			~QuadtreeNode() override;

			void TryMerge();
			void DoMerge();
			void ClearNodes();

			uint8_t GetChildrenObjectsNumber() const;
			uint8_t GetChildrenNodesNumber() const;
		
			void AddObject(const RePtr<ReObject>& obj);
			void RemoveObject(const RePtr<ReObject>& Re);
		
			QuadtreeNode& operator=(const QuadtreeNode& other);
			QuadtreeNode& operator=(QuadtreeNode&& other) noexcept;

		private:
			uint8_t m_maxObjectsPerNode;
		
			// Actually should be a physics comp but we don't have one yet
			std::vector<RePtr<ReObject>> m_childrenObjects;
			// std::shared_ptr because we want to easily copy another tree
			// AHAH cant use shared otherwise the copy will modify the actual one
			std::vector<QuadtreeNode*> m_childrenNodes;
	};
}


