#pragma once

namespace Re
{
    ReObjectTemplate
    RCSdlEventReceiver<T>::RCSdlEventReceiver(ReObject* owner, void(T::* func)(SDL_Event&)) : ReComponent(owner, -1)
    {
        m_eventFunc = func;
    }

    ReObjectTemplate
    void RCSdlEventReceiver<T>::OnObjectCreated()
    {
        IWorldObject::OnObjectCreated();
        GetEngine()->RegisterInputEventListener(this);
    }

    ReObjectTemplate
    void RCSdlEventReceiver<T>::OnEventReceived(SDL_Event& event)
    {
        (GetOwnerAs<T>()->*m_eventFunc)(event);
    }
}
