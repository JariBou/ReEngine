#include <thread>
#include <RealEngine/Core/Physics/Quadtree.h>

namespace Re
{
    void Quadtree::Rebuild()
    {
        m_is_rebuilding = true;
        m_wants_to_rebuild = false;

        QuadtreeNode newNode = QuadtreeNode();

        //TODO

        root = newNode;
        
        m_is_rebuilding = false;
    }

    void Quadtree::RebuildAsync()
    {
        // if (m_rebuild_thread.joinable())
        if (m_is_rebuilding)
        {
            m_wants_to_rebuild = true;
            return;
        }
        m_rebuild_thread = std::thread(Rebuild);
    }
}
