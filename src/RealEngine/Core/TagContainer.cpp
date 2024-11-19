#include <RealEngine/Core/TagContainer.h>

namespace Re
{
    const std::vector<std::string>& TagContainer::GetTags() const
    {
        return m_tags;
    }

    bool TagContainer::HasTag(const std::string& tag) const
    {
        return std::ranges::find(m_tags, tag) != m_tags.end();
    }

    void TagContainer::SetTags(std::vector<std::string>&& tags)
    {
        m_tags = std::move(tags);
    }
}
