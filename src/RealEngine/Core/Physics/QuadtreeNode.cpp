#include <RealEngine/Core/Physics/QuadtreeNode.h>

namespace Re
{
    QuadtreeNode::QuadtreeNode()
    {
        m_childrenObjects.reserve(4);
        m_childrenNodes.reserve(4);
    }

    QuadtreeNode::QuadtreeNode(const QuadtreeNode& other) : m_childrenObjects(other.m_childrenObjects),
                                                            m_childrenNodes(other.m_childrenNodes)
    {
    }

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
