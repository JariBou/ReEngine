#pragma once

#include <RealEngine/Core/Export.h>
#include <SDL_events.h>

namespace Re
{
	class RE_CORE_API SdlEventListener
	{
		public:
			
			virtual void OnEventReceived(SDL_Event& event) = 0;

	};
}


