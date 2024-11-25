#include <RealEngine/Core/Physics/QuadtreeNode.h>

namespace Re
{
    QuadtreeNode::QuadtreeNode() : m_maxObjectsPerNode(4)
    {
        m_childrenObjects.reserve(m_maxObjectsPerNode);
        m_childrenNodes.reserve(m_maxObjectsPerNode);
    }

    QuadtreeNode::QuadtreeNode(uint8_t maxObjectsPerNode) : m_maxObjectsPerNode(maxObjectsPerNode)
    {
    }

    QuadtreeNode::QuadtreeNode(const QuadtreeNode& other) :
    m_maxObjectsPerNode(other.m_maxObjectsPerNode),
    m_childrenObjects(other.m_childrenObjects),
    m_childrenNodes(other.m_childrenNodes)
    {
    }

    QuadtreeNode::QuadtreeNode(QuadtreeNode&& other) noexcept :
    m_maxObjectsPerNode(other.m_maxObjectsPerNode),
    m_childrenObjects(std::move(other.m_childrenObjects)),
    m_childrenNodes(std::move(other.m_childrenNodes))
    {
    }

    void QuadtreeNode::TryMerge()
    {
        for (const std::shared_ptr<QuadtreeNode>& childrenNode : m_childrenNodes)
        {
            childrenNode->TryMerge();
        }

        DoMerge();
    }

    void QuadtreeNode::DoMerge()
    {
        uint8_t childrenNumber = GetChildrenObjectsNumber();
        for (const std::shared_ptr<QuadtreeNode>& childrenNode : m_childrenNodes)
        {
            if (childrenNode->GetChildrenNodesNumber() > 0) return;
            childrenNumber += childrenNode->GetChildrenObjectsNumber();
        }

        if (childrenNumber <= m_maxObjectsPerNode)
        {
            // need to find a way to merge these two
            for (const std::shared_ptr<QuadtreeNode>& childrenNode : m_childrenNodes)
            {
                m_childrenObjects.insert(m_childrenObjects.begin(), childrenNode->m_childrenObjects.begin(), childrenNode->m_childrenObjects.end());
                childrenNode->ClearNodes();
            }
        }

    }

    void QuadtreeNode::ClearNodes()
    {
        m_childrenNodes.clear();
    }

    uint8_t QuadtreeNode::GetChildrenObjectsNumber() const
    {
        return static_cast<uint8_t>(m_childrenObjects.size());
    }

    uint8_t QuadtreeNode::GetChildrenNodesNumber() const
    {
        return static_cast<uint8_t>(m_childrenNodes.size());
    }

    void QuadtreeNode::AddObject(const RePtr<ReObject>& obj)
    {
    }

    // Wtf why no error on self assignment thing like in RePtr?
    QuadtreeNode& QuadtreeNode::operator=(const QuadtreeNode& other) : m_childrenObjects(other.m_childrenObjects),
                                                                       m_childrenNodes(other.m_childrenNodes)
    {
        return *this;
    }

    QuadtreeNode& QuadtreeNode::operator=(QuadtreeNode&& other)  noexcept : m_childrenObjects(std::move(other.m_childrenObjects)),
                                                                            m_childrenNodes(std::move(other.m_childrenNodes))
    {
        return *this;
    }
}
