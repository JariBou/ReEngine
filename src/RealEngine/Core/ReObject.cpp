#include <RealEngine/Core/ReObject.h>
#include <RealEngine/Core/ReEngine.h>
#include <RealEngine/Core/ReEngine.h>

namespace Re
{
    ReObject::ReObject(ReEngine* engine) : m_engine(engine)
    {
    }

    ReObject::~ReObject()
    {
        GetWorld()->ScheduleDestroy(this);
    }

    void ReObject::Tick()
    {
    }
    World* ReObject::GetWorld()
    {
        return m_engine->GetWorld();
    }

    bool ReObject::ShouldTick()
    {
        return m_shouldTick;
    }

    void ReObject::SetShouldTick(bool state)
    {
        m_shouldTick = state;
    }
}
