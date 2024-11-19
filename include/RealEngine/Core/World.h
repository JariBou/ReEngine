#pragma once

#include <RealEngine/Core/Export.h>
#include <RealEngine/Core/ObjectHandling/RePtr.h>
#include <vector>
#include <map>

namespace Re
{
	class ReComponent;
}

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


// #pragma region Components
// 			// template<Derived<ReObject> T>
// 			// RePtr<T> GetRePtrTo(ReObject* object);
// 		
// 			RePtr<ReObject> GetRePtrTo(ReObject* object);
//
// 			template<Derived<ReComponent> T>
// 			void RegisterComponent(RePtr<T>* component, RePtr<ReObject>* owner);
//
// 			// Honestly this should take like a RePtr, I busted my ass to create them so lets use them alr?
// 			template<Derived<ReComponent> T>
// 			RePtr<T> CreateComponent(ReObject* owner);
//
// 			template<Derived<ReComponent> T>
// 		    size_t GetObjectIndex(RePtr<T>* component);
// 		private:
// 			std::map<size_t, std::vector<ReMasterPtr<ReComponent>>> m_componentMap;
//
// 		
// #pragma endregion
	public:
			// template<Derived<ReObject> T, typename... Args>
			// RePtr<T> InstantiateObject(Args&&... ObjectParameters);

			World& operator=(const World&) = delete;
			World& operator=(World&&) = delete;

#pragma region ObjectCreation

		template<typename T, typename... Args>
		RePtr<T> InstantiateObject(Args&&... objectParameters);

		template<typename T>
		void AddObjectToWorld(T* object);
		
#pragma endregion

#pragma region GarbageCollector

		void ScheduleObjectDestroy(ReObject* object);
		void ScheduleComponentDestroy(ReComponent* component);
		
		void CollectGarbage();
		
#pragma endregion

		private:
			ReEngine* m_engine;
		
			std::vector<ReObject*> m_objects;
			// std::vector<ReMasterPtr<ReObject>> m_objectsV2;
			std::vector<ReObject*> m_objectGarbage;
			std::vector<ReComponent*> m_componentGarbage;
			// std::vector<ReMasterPtr<ReObject>> m_garbageV2;

			std::vector<RendererComponent*> m_renderedObjects;

			std::map<ReObject*, std::vector<ReComponent*>> m_objectsMap;


			// template<Derived<ReObject> T>
			// void AddObjectToWorld(ReMasterPtr<T>& item);
	};
	
}

#include <RealEngine/Core/World.inl>
