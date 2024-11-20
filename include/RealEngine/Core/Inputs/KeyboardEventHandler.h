#pragma once

#include <vector>
#include <RealEngine/Core/Export.h>

#include <RealEngine/Core/Components/Interfaces/SdlEventListener.h>
#include <RealEngine/Core/ObjectHandling/ReHandledObject.h>


namespace Re
{
	typedef enum
	{
		Horizontal = 0x0000,
		Vertical = 0x0001,
		Height = 0x0010,
		
		Dim2 = 0x0100,
		Dim3 = 0x0101,
	} KB_AxisName;
	
	class AxisInfo
	{
	public:
		KB_AxisName axisName;
		std::vector<SDL_Scancode> keysNegative;
		std::vector<SDL_Scancode> keysPositive;

		AxisInfo(): axisName()
		{
		}

		AxisInfo(KB_AxisName inAxisName, std::vector<SDL_Scancode>&& inKeysNegative, std::vector<SDL_Scancode>&& inKeysPositive) : axisName(inAxisName)
		{
			keysNegative = std::move(inKeysNegative);
			keysPositive = std::move(inKeysPositive);
		}
	};

	class RE_CORE_API KeyboardEventHandler : public ReHandledObject<KeyboardEventHandler>, public SdlEventListener
	{
		public:
			virtual void RegisterAxisInfo(KB_AxisName axisName, AxisInfo& inAxisInfo) = 0;
			virtual void RegisterAxisInfo(KB_AxisName axisName, AxisInfo&& inAxisInfo) = 0;
		
			virtual bool GetKeyState(SDL_Scancode key) const = 0;

			virtual float GetAxis(KB_AxisName axisName) const = 0;

			template<typename T>
			T GetAxis(KB_AxisName axisName) const
			{
				return static_cast<T>(GetAxis(axisName));	
			}
		
		protected:
			virtual float ProcessAxisDemand(const AxisInfo& axisInfo) const = 0;
			virtual bool GetAxisKeysState(const std::vector<SDL_Scancode>& axisKeysList) const = 0;
	};
}


