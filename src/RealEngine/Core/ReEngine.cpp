#include <SDL_timer.h>
#include <RealEngine/Core/ReEngine.h>
#include <RealEngine/Core/World.h>
#include <RealEngine/Core/Components/Interfaces/SdlEventListener.h>

#include "RealEngine/Core/Inputs/KeyboardHandler.h"

namespace Re
{
	ReEngine::ReEngine()
	{
		m_world = new World(this);
		m_keyboardHandler = new KeyboardHandler();
		RegisterInputEventListener(m_keyboardHandler);
	}

	WindowHandler* ReEngine::InitWindow(FWindowInfo wi)
	{
		m_windowHandler = new WindowHandler(wi);
		return m_windowHandler;
	}

	Renderer* ReEngine::GetRenderer() const
	{
		if (m_windowHandler == nullptr) return nullptr;
		return m_windowHandler->GetRenderer();
	}

	World* ReEngine::GetWorld() const
	{
		return m_world;
	}

	const KeyboardHandler* ReEngine::GetKbHandler() const
	{
			return m_keyboardHandler;
	}

	void ReEngine::Start()
	{
		isRunning = true;
		while (isRunning)
		{
			Tick();
			SDL_Delay(1000 / m_targetFramerate);
		}
	}

	void ReEngine::Stop() const
	{
		isRunning = false;
	}

	void ReEngine::PollEvents() const
	{
		SDL_Event event;
		while (WindowHandler::PollEvent(event))
		{
			if (event.type == SDL_QUIT)
			{
				Stop();
				return;
			}
			for (SdlEventListener* listener : m_inputListeners)
			{
				listener->OnEventReceived(event);
			}
		}
	}

	void ReEngine::Tick()
	{
		GetRenderer()->RenderClear();

		PollEvents();

		GetWorld()->PhysicsTick();
		GetWorld()->Tick();
		
		GetRenderer()->UpdateRenderer();
		// GetWorld()->RenderTick(); // Maybe should be separated idk
	}

	void ReEngine::Update()
	{
	}

	void ReEngine::PhysicsUpdate()
	{
	}

	void ReEngine::RegisterInputEventListener(SdlEventListener* inputReceiver)
	{
		m_inputListeners.push_back(inputReceiver);
	}
	
}
