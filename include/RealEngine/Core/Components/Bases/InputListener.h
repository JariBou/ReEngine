#pragma once

#include <SDL_events.h>
#include <RealEngine/Core/Export.h>

namespace Re
{
	class RE_CORE_API InputListener
	{
		public:
			
			virtual void OnEventReceived(SDL_Event& event) = 0;

	};
}


