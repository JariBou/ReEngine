#include <algorithm>
#include <iostream>
#include <ostream>
#include <RealEngine/Core/Inputs/KeyboardHandler.h>

namespace Re
{
    KeyboardHandler::KeyboardHandler()
    {
        m_axisInfoMap[KB_AxisName::Horizontal] = AxisInfo(KB_AxisName::Horizontal, {SDL_SCANCODE_LEFT, SDL_SCANCODE_A}, {SDL_SCANCODE_RIGHT, SDL_SCANCODE_D});
        m_axisInfoMap[KB_AxisName::Vertical] = AxisInfo(KB_AxisName::Vertical, {SDL_SCANCODE_UP, SDL_SCANCODE_W}, {SDL_SCANCODE_DOWN, SDL_SCANCODE_S});
    }

    void KeyboardHandler::OnEventReceived(SDL_Event& event)
    {
        // std::cout << "KeyboardHandler::OnEventReceived" << event.key.keysym.sym << std::endl;
        m_keyStateMap[event.key.keysym.scancode] = event.key.state;
    }

    bool KeyboardHandler::GetKeyState(SDL_Scancode key) const
    {
        if (m_keyStateMap.contains(key)) return  m_keyStateMap.at(key);
        return false;
    }

    int KeyboardHandler::GetAxis(KB_AxisName axisName) const
    {
        if (m_axisInfoMap.contains(axisName)) return ProcessAxisDemand(m_axisInfoMap.at(axisName));
        return 0;
    }

    int KeyboardHandler::ProcessAxisDemand(const AxisInfo& axisInfo) const
    {
        bool neg = GetAxisKeysState(axisInfo.keysNegative);
        bool pos = GetAxisKeysState(axisInfo.keysPositive);
        if ((neg && pos) || (!neg && !pos)) return 0;
        return neg ? -1 : 1;
    }
    
    bool KeyboardHandler::GetAxisKeysState(const std::vector<SDL_Scancode>& axisKeysList) const
    {
        return std::ranges::any_of(axisKeysList, [&](const SDL_Scancode& key){ return GetKeyState(key);});
        // for (SDL_Keycode keycode : axisKeysList)
        // {
        //     if (GetKeyState(keycode)) return true;
        // }
        // return false;
    }
}
