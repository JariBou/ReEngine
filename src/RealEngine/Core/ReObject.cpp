#include <RealEngine/Core/ReObject.h>
#include <RealEngine/Core/ReEngine.h>

namespace Re
{
    ReObject::ReObject(ReEngine* engine) : m_engine(engine)
    {
    }

    ReObject::~ReObject()
    {
        //GetWorld()->ScheduleDestroy(this);
    }

    void ReObject::Tick()
    {
    }

    void ReObject::DestroyObject()
    {
        GetWorld()->ScheduleDestroy(this);
    }

    World* ReObject::GetWorld() const
    {
        return m_engine->GetWorld();
    }

    bool ReObject::ShouldTick() const
    {
        return m_shouldTick;
    }

    void ReObject::SetShouldTick(bool state)
    {
        m_shouldTick = state;
    }
}
