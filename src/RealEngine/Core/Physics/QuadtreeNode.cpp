#include <map>
#include <unordered_set>
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
    m_childrenObjects(other.m_childrenObjects)
    {
        for (QuadtreeNode* node : other.m_childrenNodes)
        {
            m_childrenNodes.push_back(new QuadtreeNode(*node));            
        }
    }

    QuadtreeNode::QuadtreeNode(QuadtreeNode&& other) noexcept :
    m_maxObjectsPerNode(other.m_maxObjectsPerNode),
    m_childrenObjects(std::move(other.m_childrenObjects)),
    m_childrenNodes(std::move(other.m_childrenNodes))
    {
    }

    QuadtreeNode::~QuadtreeNode()
    {
        for (QuadtreeNode* node : m_childrenNodes)
        {
            delete node;
        }
    }

    void QuadtreeNode::TryMerge()
    {
        for (QuadtreeNode* childrenNode : m_childrenNodes)
        {
            childrenNode->TryMerge();
        }

        DoMerge();
    }

    void QuadtreeNode::DoMerge()
    {
        if (GetChildrenNodesNumber() == 0) return;
        
        std::unordered_set<QuadtreeNode*> nodes;
        for (QuadtreeNode* childrenNode : m_childrenNodes)
        {
            if (childrenNode->GetChildrenNodesNumber() == 0) return;
            
            nodes.insert(childrenNode);
            // childrenNodes.insert(childrenNodes.begin(), childrenNode->m_childrenObjects.begin(), childrenNode->m_childrenObjects.end());
            if (nodes.size() > m_maxObjectsPerNode) return;
            // if (childrenNode->GetChildrenNodesNumber() > 0) return;
            // childrenNumber += childrenNode->GetChildrenObjectsNumber();
        }

        for (QuadtreeNode* quadtreeNode : nodes)
        {
            m_childrenNodes.push_back(quadtreeNode);
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
        m_childrenObjects.push_back(obj);
    }

    void QuadtreeNode::RemoveObject(const RePtr<ReObject>& obj)
    {
        std::erase(m_childrenObjects, obj);
    }

    // Wtf why no error on self assignment thing like in RePtr?
    QuadtreeNode& QuadtreeNode::operator=(const QuadtreeNode& other)
    {
        m_childrenObjects = other.m_childrenObjects;
        m_childrenNodes = other.m_childrenNodes;
        return *this;
    }

    QuadtreeNode& QuadtreeNode::operator=(QuadtreeNode&& other)  noexcept
    {
        m_childrenObjects = std::move(other.m_childrenObjects);
        m_childrenNodes = std::move(other.m_childrenNodes);
        return *this;
    }
}
