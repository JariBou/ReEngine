#pragma once

#include <RealEngine/Core/Export.h>
#include <RealEngine/Core/ObjectHandling/RePtr.h>
#include <vector>
#include <map>

namespace Re
{
	class ReObject;
	class ReEngine;
	class ReComponent;
	class IWorldObject;
	
	template<typename T, typename U>
	concept Derived = std::is_base_of_v<U, T>;
	
	class RE_CORE_API World
	{
		public:
			World(ReEngine* inEngine);
			World(const World&) = delete;
			World(World&&) = delete;
			~World() = default;

			ReEngine* GetEngine() const;
			void PhysicsTick();
			void Tick();
			void RenderTick() const;

			World& operator=(const World&) = delete;
			World& operator=(World&&) = delete;

#pragma region ObjectCreation

		template<Derived<IWorldObject> T, typename... Args>
		RePtr<T> InstantiateObject(Args&&... objectParameters);

		IWorldObjectTemplate
		void AddObjectToWorld(T* object);
		
#pragma endregion

#pragma region GarbageCollector

		void ScheduleObjectDestroy(ReObject* object);
		void ScheduleComponentDestroy(ReComponent* component);
		
		void CollectGarbage();
		
#pragma endregion

		private:
			ReEngine* m_engine;
		
			std::vector<ReObject*> m_objectGarbage;
			std::vector<ReComponent*> m_componentGarbage;
			std::map<ReObject*, std::vector<ReComponent*>> m_objectsMap;

	};
	
}

#include <RealEngine/Core/World.inl>
