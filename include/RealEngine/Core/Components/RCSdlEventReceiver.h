#pragma once

#include <RealEngine/Core/Export.h>

#include "ReComponent.h"
#include "Interfaces/SdlEventListener.h"

#ifndef EventFuncDef
#define inEventFunc void (T::*func)(SDL_Event& /* maybe take in delta time in the future, idk */)
#define varEventFunc void (T::*m_eventFunc)(SDL_Event&/* maybe take in delta time in the future, idk */)
#define EventFuncDef
#endif

namespace Re
{
	ReObjectTemplate
	class RCSdlEventReceiver : public ReComponent, public SdlEventListener
	{
		//TODO: https://stackoverflow.com/questions/1252976/how-to-handle-multiple-keypresses-at-once-with-sdl
		public:
			RCSdlEventReceiver(ReObject* owner, inEventFunc);
			RCSdlEventReceiver(const RCSdlEventReceiver&) = delete;
			RCSdlEventReceiver(RCSdlEventReceiver&&) = delete;
			~RCSdlEventReceiver() override = default;

			RCSdlEventReceiver& operator=(const RCSdlEventReceiver&) = delete;
			RCSdlEventReceiver& operator=(RCSdlEventReceiver&&) = delete;
		
			/**
			 * You should Always call this in children unless you want to override the Creation behaviour
			 */
			void OnObjectCreated() override;

			void OnEventReceived(SDL_Event& event) override;

		private:
			varEventFunc;
	};
}

#include <RealEngine/Core/Components/RCSdlEventReceiver.inl>

