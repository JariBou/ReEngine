#include <RealEngine/Core/ReEngine.h>
#include <RealEngine/Core/World.h>

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

	Renderer* ReEngine::GetRenderer()
	{
		if (m_windowHandler == nullptr) return nullptr;
		return m_windowHandler->GetRenderer();
	}

	void ReEngine::Tick()
	{
		GetRenderer()->RenderClear();

		GetWorld()->PhysicsTick();
		GetWorld()->Tick();
		
		GetRenderer()->UpdateRenderer();
		// GetWorld()->RenderTick(); // Maybe should be separated idk
	}

	World* ReEngine::GetWorld()
	{
		return m_world;
	}

	void ReEngine::Update()
	{
	}

	void ReEngine::PhysicsUpdate()
	{
	}
}
