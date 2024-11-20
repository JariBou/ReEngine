#pragma once

#include <RealEngine/Core/Export.h>
#include <SDL_events.h>

namespace Re
{
	class RE_CORE_API SdlEventListener
	{
		public:
			SdlEventListener() = default;
			SdlEventListener(const SdlEventListener&) = delete;
			SdlEventListener(SdlEventListener&&) = delete;
			virtual ~SdlEventListener() = default;

			virtual void OnEventReceived(SDL_Event& event) = 0;

	};
}


