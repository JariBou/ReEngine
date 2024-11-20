#include <RealEngine/Core/IWorldObject.h>

namespace Re
{
    void IWorldObject::OnPreComponentRegister()
    {
    }
    
    /**
     * With default implementation:
     * - Is not guaranteed to be in order of creation
     * - Is not guaranteed to be called if created via custom way
     */
    void IWorldObject::OnObjectCreated()
    {
        m_isCreated = true;
    }

    bool IWorldObject::IsCreated()
    {
        return m_isCreated;
    }

    bool IWorldObject::IsPendingDestroy() const
    {
        return m_isPendingDestroy;
    }
}
