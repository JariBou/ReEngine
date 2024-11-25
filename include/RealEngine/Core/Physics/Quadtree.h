#pragma once

#include <vector>
#include <RealEngine/Core/Export.h>

#include "QuadtreeNode.h"

namespace Re
{
	class ReObject;

	//TODO: All RePtr<ReObject> will change to RePtr<PhysicalComponent> or smth like that

	class RE_CORE_API Quadtree
	{
		public:
			Quadtree(uint8_t maxObjectsPerNode);
			Quadtree(const Quadtree&) = delete;
			Quadtree(Quadtree&&) = delete;
			~Quadtree();

			void AddObject(const RePtr<ReObject> obj);
		
			Quadtree& operator=(const Quadtree&) = delete;
			Quadtree& operator=(Quadtree&&) = delete;

		private:
			uint8_t m_maxObjectsPerNode;
		
			QuadtreeNode root;
			std::thread m_rebuildThread;

#pragma region Rebuilding
		public:
			void Rebuild();
			void RebuildAsync();

			void LockRoot();
			void UnlockRoot();
		
		private:
			std::vector<RePtr<ReObject>> m_addedObjects;
			bool m_wantsToRebuild;
			bool m_isRebuilding;
			bool m_isRootLocked;
#pragma endregion
	};
}


