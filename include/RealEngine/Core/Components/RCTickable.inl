#pragma once

namespace Re
{
    template <typename T>
    RCTickable<T>::RCTickable(ReObject* owner, void(T::* func)()) : ReComponent(owner, -1)
    {
        m_tickFunc = func;
    }

    template <typename T>
    void RCTickable<T>::TickComponent()
    {
        (GetOwnerAs<T>()->*m_tickFunc)();
    }
}
