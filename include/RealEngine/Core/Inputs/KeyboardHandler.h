#pragma once

#include <RealEngine/Core/Export.h>
#include <RealEngine/Core/Inputs/KeyboardEventHandler.h>
#include <SDL_keycode.h>
#include <map>

namespace Re
{
	class RE_CORE_API KeyboardHandler : public KeyboardEventHandler
	{
		public:
			KeyboardHandler();
			
			void OnEventReceived(SDL_Event& event) override;

			bool GetKeyState(SDL_Scancode key) const override;

			float GetAxis(KB_AxisName axisName) const override;
				
		protected:
			float ProcessAxisDemand(const AxisInfo& axisInfo) const override;
			bool GetAxisKeysState(const std::vector<SDL_Scancode>& axisKeysList) const override;

		public:
			void RegisterAxisInfo(KB_AxisName axisName, AxisInfo& inAxisInfo) override;
			void RegisterAxisInfo(KB_AxisName axisName, AxisInfo&& inAxisInfo) override;

		protected:
			std::map<SDL_Scancode, uint8_t> m_keyStateMap;
			std::map<KB_AxisName, AxisInfo> m_axisInfoMap;
	};
}


