#pragma once

namespace Re
{
    ReObjectTemplate
    RCTickable<T>::RCTickable(ReObject* owner, inTickFunc) : ReComponent(owner, -1)
    {
        m_tickFunc = func;
        SetShouldTick(true);
    }

    ReObjectTemplate
    void RCTickable<T>::TickComponent()
    {
        (GetOwnerAs<T>()->*m_tickFunc)();
    }
}
