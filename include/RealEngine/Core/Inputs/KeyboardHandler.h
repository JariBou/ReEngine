#pragma once

#include <RealEngine/Core/Export.h>
#include <SDL_keycode.h>
#include <map>
#include <string>
#include <vector>

#include <RealEngine/Core/Components/Interfaces/SdlEventListener.h>
#include <RealEngine/Core/ObjectHandling/ReHandledObject.h>

namespace Re
{
	
	typedef enum
	{
		Horizontal = 'h',
		Vertical = 'v',
	} KB_AxisName;
	
	class AxisInfo
	{
		public:
			KB_AxisName axisName;
			std::vector<SDL_Keycode> keysNegative;
			std::vector<SDL_Keycode> keysPositive;

			AxisInfo(): axisName()
			{
			}

			AxisInfo(KB_AxisName inAxisName, std::vector<SDL_Keycode>&& inKeysNegative, std::vector<SDL_Keycode>&& inKeysPositive) : axisName(inAxisName)
			{
				keysNegative = std::move(inKeysNegative);
				keysPositive = std::move(inKeysPositive);
			}
	};
	
	class RE_CORE_API KeyboardHandler : public ReHandledObject<KeyboardHandler>, public SdlEventListener
	{
		public:
			KeyboardHandler();
		
			void OnEventReceived(SDL_Event& event) override;

			bool GetKeyState(SDL_Keycode key) const;

			int GetAxis(KB_AxisName axisName) const;

	
		private:
			int ProcessAxisDemand(const AxisInfo& axisInfo) const;
			bool GetAxisKeysState(const std::vector<SDL_Keycode>& axisKeysList) const;
		
			std::map<SDL_Keycode, uint8_t> m_keyStateMap;
			std::map<KB_AxisName, AxisInfo> m_axisInfoMap;
	};
}


