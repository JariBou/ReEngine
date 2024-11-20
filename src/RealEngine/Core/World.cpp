#include <RealEngine/Core/World.h>
#include <RealEngine/Core/ReObject.h>
#include <RealEngine/Core/ReEngine.h>
#include <RealEngine/Core/Utils/StdUtils.h>

#include "RealEngine/Core/Components/ReComponent.h"

namespace Re
{
    World::World(ReEngine* inEngine) : m_engine(inEngine)
    {
	}

    ReEngine* World::GetEngine() const
    {
        return m_engine;
    }

    void World::PhysicsTick()
    {
    }

    void World::Tick()
    {
        for (auto& [object, componentList] : m_objectsMap)
        {
            for (ReComponent* component : componentList)
            {
                if (component->ShouldTick()) component->TickComponent();
            }
        }

        CollectGarbage();
    }

    void World::RenderTick() const
    {
        
    }

    void World::ScheduleObjectDestroy(ReObject* object)
    {
        if (m_objectGarbage.size() == m_objectGarbage.capacity()) m_objectGarbage.reserve(m_objectGarbage.capacity() * 2);
        m_objectGarbage.push_back(object);
    }

    void World::ScheduleComponentDestroy(ReComponent* component)
    {
        if (m_componentGarbage.size() == m_componentGarbage.capacity()) m_componentGarbage.reserve(m_componentGarbage.capacity() * 2);
        m_componentGarbage.push_back(component);
    }

    void World::CollectGarbage()
    {
        for (ReObject* obj : m_objectGarbage)
        {
            for (ReComponent* component : m_objectsMap[obj])
            {
                component->OnObjectDestroyed();
                delete component;
            }
            MapUtils::RemoveElementByKey(m_objectsMap, obj);
            obj->OnObjectDestroyed();
            delete obj;
        }

        m_objectGarbage.clear();

        for (ReComponent* component : m_componentGarbage)
        {
            if (m_objectsMap.contains(component->GetOwner()))
            {
                std::vector<ReComponent*>& components = m_objectsMap[component->GetOwner()];
                ArrayUtils::RemoveElement(components, component);
                delete component;
            }
        }
        
        m_componentGarbage.clear();
    }
    
}
