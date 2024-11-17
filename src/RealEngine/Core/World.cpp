#include <RealEngine/Core/World.h>
#include <RealEngine/Core/ReObject.h>
#include <iostream>

#include "RealEngine/Core/ReEngine.h"

namespace Re
{
    World::World(ReEngine* inEngine) : m_engine(inEngine)
    {
		m_objectsV2.resize(4);
	}

    void World::PhysicsTick()
    {
    }

    void World::Tick()
    {
        for(ReObject* var : m_objects)
        {
            if (var->ShouldTick()) var->Tick();
        }
		for (ReMasterPtr<ReObject>& var : m_objectsV2)
		{
			if (var->ShouldTick()) var->Tick();
		}

        // for (ReMasterPtr<ReObject>* var : m_objectsV2)
        // {
        //     if (var->Get()->ShouldTick()) var->Get()->Tick();
        // }
        CollectGarbage();
    }

    void World::RenderTick() const
    {
        for (RendererComponent* comp : m_renderedObjects) {
            comp->Render(m_engine->GetRenderer());
        }
    }

    void World::ScheduleDestroy(ReObject* object)
    {
        m_garbage.push_back(object);
        
    }

    void World::CollectGarbage()
    {
        auto it = m_garbage.begin();
        while (it != m_garbage.end()) {
            m_garbage.erase(it);
        }

		auto it2 = m_garbageV2.begin();
		while (it2 != m_garbageV2.end()) {
            auto objectIt = std::find(m_objectsV2.begin(), m_objectsV2.end(), *it2);
		    m_garbageV2.erase(objectIt);
            m_garbageV2.erase(it2);
		}
    }

#pragma region Components

    // Wait maybe use a master ptr?
    // or leave the handling to the object...
    void World::RegisterComponent(ReObject* object, ReComponent* component)
    {
        size_t objectIndex = GetObjectIndex(object);
        m_componentMap[objectIndex].emplace_back(component);
        return;
        if (auto it = m_componentMap.find(objectIndex); it != m_componentMap.end())
        {
            it->second.push_back(component);
        } else
        {
            m_componentMap[objectIndex].push_back(component);
        }
    }

    size_t World::GetObjectIndex(ReObject* object)
    {
        if (object == nullptr) return -1;
        auto it = std::find(m_objectsV2.begin(), m_objectsV2.end(), object);
        if (it == m_objectsV2.end()) return -1;
        return std::distance(m_objectsV2.begin(), it);
    }
    
#pragma endregion

}
