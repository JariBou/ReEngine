#include <algorithm>
#include <RealEngine/Core/ReObject.h>
#include <RealEngine/Core/ReEngine.h>

#include "RealEngine/Core/Components/ReComponent.h"

namespace Re
{
    ReObject::ReObject(ReEngine* engine) : m_engine(engine)
    {
    }

    ReObject::~ReObject()
    {
        //GetWorld()->ScheduleDestroy(this);
    }

    void ReObject::DestroyObject()
    {
        GetWorld()->ScheduleObjectDestroy(this);
    }

    /**
     * You should always call ReObject::RegisterComponents at the end of your registerComponents unless you
     * want to manually reorder components
     * @param componentList 
     */
    void ReObject::RegisterComponents(std::vector<ReComponent*>& componentList)
    {
        std::ranges::sort(componentList,[](const ReComponent* compA, const ReComponent* compB)
        {
            return compA->GetPriority() > compB->GetPriority();
        });
    }

    World* ReObject::GetWorld() const
    {
        return m_engine->GetWorld();
    }
}
