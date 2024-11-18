#include <RealEngine/Core/World.h>
#include <RealEngine/Core/ReObject.h>
#include <RealEngine/Core/ReEngine.h>
#include <RealEngine/Core/VectorUtils.h>
#include <RealEngine/Core/RendererComponent.h>

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
        for(ReObject* var : m_objects)
        {
            if (var->ShouldTick()) var->Tick();
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
        for (RendererComponent* comp : m_renderedObjects) {
            comp->Render(m_engine->GetRenderer());
        }
    }

    void World::ScheduleDestroy(ReObject* object)
    {
        if (m_garbage.size() == m_garbage.capacity()) m_garbage.reserve(m_garbage.capacity() * 2);
        m_garbage.push_back(object);
    }

    void World::CollectGarbage()
    {
        // auto it = m_garbage.begin();
        // while (it != m_garbage.end()) {
        //     delete *it;
        //     m_garbage.erase(it);
        // }
        for (ReObject* obj : m_garbage)
        {
            VectorUtils::RemoveElement(m_objects, obj);
            delete obj;
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
        
        m_garbage.clear();
        m_garbage.shrink_to_fit();
        m_garbage.reserve(16);
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
