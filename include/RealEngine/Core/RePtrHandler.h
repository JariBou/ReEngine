#pragma once

#include <RealEngine/Core/Export.h>

namespace Re
{
	class RE_CORE_API RePtrHandler
	{
		public:
			RePtrHandler() = default;
			RePtrHandler(const RePtrHandler&) = delete;
			RePtrHandler(RePtrHandler&&) = delete;
			~RePtrHandler() = default;

			RePtrHandler& operator=(const RePtrHandler&) = delete;
			RePtrHandler& operator=(RePtrHandler&&) = delete;

		private:
	};
}


