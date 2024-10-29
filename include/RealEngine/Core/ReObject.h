#pragma once

#include <RealEngine/Core/Export.h>

namespace Re
{
	class ReEngine;

	class RE_CORE_API ReObject
	{
		public:
			ReObject(ReEngine* engine);

			ReObject(const ReObject&) = delete;
			ReObject(ReObject&&) = delete;
			~ReObject() = default;

			ReObject& operator=(const ReObject&) = delete;
			ReObject& operator=(ReObject&&) = delete;

		private:
			ReEngine* m_engine;
	};
}


