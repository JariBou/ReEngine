#pragma once

#include <RealEngine/Core/Export.h>

namespace Re
{
	class RE_CORE_API ReComponent
	{
		public:
			ReComponent() = default;
			ReComponent(const ReComponent&) = delete;
			ReComponent(ReComponent&&) = delete;
			~ReComponent() = default;

			ReComponent& operator=(const ReComponent&) = delete;
			ReComponent& operator=(ReComponent&&) = delete;

		private:
	};
}


