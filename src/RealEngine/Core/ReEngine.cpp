#include <SDL_timer.h>
#include <RealEngine/Core/ReEngine.h>
#include <RealEngine/Core/World.h>
#include <RealEngine/Core/Components/Bases/InputListener.h>

namespace Re
{
	ReEngine::ReEngine()
	{
		m_world = new World(this);
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

	void ReEngine::Start()
	{
		isRunning = true;
		while (isRunning)
		{
			Tick();
			SDL_Delay(1000 / 60);
		}
	}

	void ReEngine::PollEvents() const
	{
		SDL_Event event;
		while (m_windowHandler->PollEvent(event))
		{
			if (event.type == SDL_QUIT)
			{
				isRunning = false;
				return;
			}
			for (InputListener* listener : m_inputListeners)
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

	void ReEngine::RegisterInputEventListener(InputListener* inputReceiver)
	{
		m_inputListeners.push_back(inputReceiver);
	}
}
