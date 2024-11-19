#pragma once

namespace Re
{
    ReObjectTemplate
    RCDisplayable<T>::RCDisplayable(ReObject* owner, inDisplayFunc) : ReComponent(owner, -1)
    {
        m_displayFunc = func;
    }

    ReObjectTemplate
    void RCDisplayable<T>::TickComponent()
    {
        (GetOwnerAs<T>()->*m_displayFunc)();
    }
}
