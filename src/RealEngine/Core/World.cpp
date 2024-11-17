#include <RealEngine/Core/World.h>
#include <RealEngine/Core/ReObject.h>
#include <iostream>

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

    void World::RenderTick()
    {
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
			m_garbageV2.erase(it2);
		}
    }
}
