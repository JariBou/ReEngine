#pragma once

#include <stdarg.h>
#include <string>
#include <vector>
#include <RealEngine/Core/Export.h>

namespace Re
{
	class RE_CORE_API TagContainer
	{
		public:
			const std::vector<std::string>& GetTags() const;
			bool HasTag(const std::string& tag) const;

			/**
			 * Usage: SetTags({"Tag1", "Tag2", ...})
			 * @param tags  
			 */
			void SetTags(std::vector<std::string>&& tags);

		protected:
			std::vector<std::string> m_tags;

	};

}


