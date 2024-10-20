#pragma once

#include <RealEngine/Core/Export.h>

namespace Re
{
	class RE_CORE_API ITickable
	{
		public:
			virtual void Tick() = 0;

		private:
	};
}
