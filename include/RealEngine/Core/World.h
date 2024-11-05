#pragma once

#include <RealEngine/Core/Export.h>
#include <RealEngine/Core/ReMasterPtr.h>
#include <vector>

namespace Re
{
	class ReObject;

	template<typename T, typename U>
	concept Derived = std::is_base_of_v<U, T>;
	
	class RE_CORE_API World
	{
		public:
			World() = default;
			World(const World&) = delete;
			World(World&&) = delete;
			~World() = default;

			void PhysicsTick();
			void Tick();
			void RenderTick();

			void ScheduleDestroy(ReObject* object);
			void CollectGarbage();

			template<Derived<ReObject> T>
			T* InstantiateObject();

			World& operator=(const World&) = delete;
			World& operator=(World&&) = delete;

		private:
			std::vector<ReObject*> m_objects;
			std::vector<ReMasterPtr<ReObject>> m_objectsV2;
			std::vector<ReObject*> m_garbage;
			std::vector<ReMasterPtr<ReObject>> m_garbageV2;
	};
	
}

#include <RealEngine/Core/World.inl>
