#include <RealEngine/Core/IWorldObject.h>

namespace Re
{
    void IWorldObject::OnPreComponentRegister()
    {
    }

    void IWorldObject::OnObjectCreated()
    {
    }

    bool IWorldObject::IsPendingDestroy() const
    {
        return m_isPendingDestroy;
    }
}
