#pragma once

#include <map>
#include <RealEngine/Core/Export.h>
#include <RealEngine/Core/ReMasterPtr.h>
#include <vector>

#include "ReComponent.h"

namespace Re
{
	class RendererComponent;
}

namespace Re
{
	class ReObject;
	class ReEngine;

	template<typename T, typename U>
	concept Derived = std::is_base_of_v<U, T>;
	
	class RE_CORE_API World
	{
		public:
			World(ReEngine* inEngine);
			World(const World&) = delete;
			World(World&&) = delete;
			~World() = default;

			void PhysicsTick();
			void Tick();
			void RenderTick() const;

			void ScheduleDestroy(ReObject* object);
			void CollectGarbage();

#pragma region Components

			void RegisterComponent(ReObject* object, ReComponent* component);

		    size_t GetObjectIndex(ReObject* object);
		private:
			std::map<size_t, std::vector<ReComponent*>> m_componentMap;

		
#pragma endregion

			template<Derived<ReObject> T, typename... Args>
			RePtr<T> InstantiateObject(Args&&... ObjectParameters);

			World& operator=(const World&) = delete;
			World& operator=(World&&) = delete;

		private:
			ReEngine* m_engine;
		
			std::vector<ReObject*> m_objects;
			std::vector<ReMasterPtr<ReObject>> m_objectsV2;
			std::vector<ReObject*> m_garbage;
			std::vector<ReMasterPtr<ReObject>> m_garbageV2;

			std::vector<RendererComponent*> m_renderedObjects;


			template<Derived<ReObject> T>
			void AddObjectToWorld(ReMasterPtr<T>& item);
	};
	
}

#include <RealEngine/Core/World.inl>
