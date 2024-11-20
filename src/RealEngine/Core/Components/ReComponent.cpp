#include <RealEngine/Core/Components/ReComponent.h>

#include <RealEngine/Core/ReObject.h>
#include <RealEngine/Core/ObjectHandling/RePtr.h>

#include "RealEngine/Core/World.h"

namespace Re
{
    ReComponent::ReComponent(ReObject* owner, int priority) : m_owner(owner), m_priority(priority)
    {
    }

    ReComponent* ReComponent::SetPriority(int priority)
    {
        m_priority = priority;
        return this;
    }

    RePtr<ReObject> ReComponent::GetOwner() const
    {
        return RePtr(m_owner);
    }

    int ReComponent::GetPriority() const
    {
        return m_priority;
    }

    World* ReComponent::GetWorld() const
    {
        return m_owner->GetWorld();
    }

    ReEngine* ReComponent::GetEngine() const
    {
        return GetWorld()->GetEngine();
    }
    
    bool ReComponent::ShouldTick() const
    {
        return m_shouldTick;
    }

    void ReComponent::SetShouldTick(bool state)
    {
        m_shouldTick = state;
    }

    void ReComponent::Destroy()
    {
        //TODO
    }

    void ReComponent::OnObjectDestroyed()
    {
    }

    void ReComponent::TickComponent()
    {
    }
}
