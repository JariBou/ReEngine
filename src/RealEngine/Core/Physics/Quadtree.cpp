#include <thread>
#include <RealEngine/Core/Physics/Quadtree.h>

namespace Re
{
    Quadtree::Quadtree(uint8_t maxObjectsPerNode) : m_maxObjectsPerNode(maxObjectsPerNode)
    {
        root = QuadtreeNode(m_maxObjectsPerNode);
    }

    Quadtree::~Quadtree()
    {
        if (m_isRebuilding) m_rebuildThread.join();
    }

    void Quadtree::AddObject(const RePtr<ReObject> obj)
    {
        if (m_isRebuilding) m_addedObjects.push_back(obj);
        if (!m_isRootLocked) root.AddObject(obj);
    }

    void Quadtree::Rebuild()
    {
        m_isRebuilding = true;
        m_wantsToRebuild = false;

        QuadtreeNode newNode = QuadtreeNode();

        //TODO
        LockRoot();
        root = newNode;
        UnlockRoot();
        
        m_isRebuilding = false;
    }

    void Quadtree::RebuildAsync()
    {
        // if (m_rebuild_thread.joinable())
        if (m_isRebuilding)
        {
            m_wantsToRebuild = true;
            return;
        }
        m_rebuildThread = std::thread(Rebuild);
    }

    void Quadtree::LockRoot()
    {
        m_isRootLocked = true;
    }

    void Quadtree::UnlockRoot()
    {
        m_isRootLocked = false;
    }
}
