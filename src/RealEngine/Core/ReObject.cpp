#include <algorithm>
#include <RealEngine/Core/ReObject.h>
#include <RealEngine/Core/ReEngine.h>

#include "RealEngine/Core/Components/ReComponent.h"

namespace Re
{
    ReObject::ReObject(ReEngine* engine) : m_engine(engine)
    {
    }

    
    /**
     * USE ReObject::Destroy TO DESTROY A ReObject!!
     */
    ReObject::~ReObject()
    {
        //GetWorld()->ScheduleDestroy(this);
    }

    void ReObject::Destroy()
    {
        m_isPendingDestroy = true;
        GetWorld()->ScheduleObjectDestroy(this);
    }

    void ReObject::OnObjectDestroyed()
    {
    }


    /**
     * Method called by World when creating the object.
     * You should always call ReObject::RegisterComponents at the end of your registerComponents unless you
     * want to manually reorder components
     * @param componentList ref to the World's component std::vector
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
