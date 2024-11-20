#pragma once

#include <RealEngine/Core/Export.h>

#include "ReComponent.h"
#include "Interfaces/InputListener.h"

#ifndef EventFuncDef
#define inEventFunc void (T::*func)(SDL_Event& /* maybe take in delta time in the future, idk */)
#define varEventFunc void (T::*m_eventFunc)(SDL_Event&/* maybe take in delta time in the future, idk */)
#define EventFuncDef
#endif

namespace Re
{
	ReObjectTemplate
	class RCInputReceiver : public ReComponent, public InputListener
	{
		//TODO: https://stackoverflow.com/questions/1252976/how-to-handle-multiple-keypresses-at-once-with-sdl
		public:
			RCInputReceiver(ReObject* owner, inEventFunc);
			RCInputReceiver(const RCInputReceiver&) = delete;
			RCInputReceiver(RCInputReceiver&&) = delete;
			~RCInputReceiver() override = default;

			RCInputReceiver& operator=(const RCInputReceiver&) = delete;
			RCInputReceiver& operator=(RCInputReceiver&&) = delete;
		
			/**
			 * You should Always call this in children unless you want to override the Creation behaviour
			 */
			void OnObjectCreated() override;

			void OnEventReceived(SDL_Event& event) override;

		private:
			varEventFunc;
	};
}

#include <RealEngine/Core/Components/RCInputReceiver.inl>

