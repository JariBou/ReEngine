#pragma once

namespace Re
{
    ReObjectTemplate
    RCInputReceiver<T>::RCInputReceiver(ReObject* owner, void(T::* func)(SDL_Event&)) : ReComponent(owner, -1)
    {
        m_eventFunc = func;
    }

    ReObjectTemplate
    void RCInputReceiver<T>::OnObjectCreated()
    {
        IWorldObject::OnObjectCreated();
        GetEngine()->RegisterInputEventListener(this);
    }

    ReObjectTemplate
    void RCInputReceiver<T>::OnEventReceived(SDL_Event& event)
    {
        (GetOwnerAs<T>()->*m_eventFunc)(event);
    }
}
