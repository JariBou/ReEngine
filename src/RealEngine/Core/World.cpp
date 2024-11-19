#include <RealEngine/Core/World.h>
#include <RealEngine/Core/ReObject.h>
#include <RealEngine/Core/ReEngine.h>
#include <RealEngine/Core/Utils/StdUtils.h>

#include "RealEngine/Core/Components/ReComponent.h"

namespace Re
{
    World::World(ReEngine* inEngine) : m_engine(inEngine)
    {
		m_objects.reserve(4);
		// m_objectsV2.resize(4);
	}

    void World::PhysicsTick()
    {
    }

    void World::Tick()
    {
        // for(ReObject* var : m_objects)
        // {
        //     if (var->ShouldTick()) var->Tick();
        // }

        for (auto& [object, componentList] : m_objectsMap)
        {
            for (ReComponent* component : componentList)
            {
                component->TickComponent();
            }
        }
        
		// for (ReMasterPtr<ReObject>& var : m_objectsV2)
		// {
		// 	if (var->ShouldTick()) var->Tick();
		// }

        // for (ReMasterPtr<ReObject>* var : m_objectsV2)
        // {
        //     if (var->Get()->ShouldTick()) var->Get()->Tick();
        // }
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
        //TODO test garbage collector
        // auto it = m_garbage.begin();
        // while (it != m_garbage.end()) {
        //     delete *it;
        //     m_garbage.erase(it);
        // }
        for (ReObject* obj : m_objectGarbage)
        {
            for (ReComponent* component : m_objectsMap[obj])
            {
                delete component;
            }
            MapUtils::RemoveElementByKey(m_objectsMap, obj);
            ArrayUtils::RemoveElement(m_objects, obj);
            delete obj;
        }

        for (ReComponent* component : m_componentGarbage)
        {
            if (m_objectsMap.contains(component->GetOwner()))
            {
                std::vector<ReComponent*>& components = m_objectsMap[component->GetOwner()];
                ArrayUtils::RemoveElement(components, component);
                delete component;
            }
        }

        

        if (m_objects.capacity() > 4)
        {
            size_t pow = 1;

            while (m_objects.capacity()/(2 * pow) > m_objects.size())
            {
                pow *= 2;
            }
            if (pow > 1)
            {
                m_objects.reserve(m_objects.capacity()/pow);
            }
        }
        
        m_objectGarbage.clear();
        m_objectGarbage.shrink_to_fit();
        m_objectGarbage.reserve(16);
    }

    // template <Derived<ReObject> T>
    // RePtr<ReObject> World::GetRePtrTo(ReObject* object)
    // {
    //     auto it = m_objectsV2.begin();
    //     while (it != m_objectsV2.end())
    //     {
    //         if (*it == object) return RePtr(*it);
    //     }
    //     return nullptr;
    // }

}
