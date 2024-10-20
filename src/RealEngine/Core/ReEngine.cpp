#include <RealEngine/Core/ReEngine.h>

namespace Re
{
	WindowHandler* ReEngine::InitWindow(WindowInfo wi)
	{
		m_windowHandler = new WindowHandler(wi);
		return m_windowHandler;
	}

	Renderer* ReEngine::GetRenderer()
	{
		if (m_windowHandler == nullptr) return nullptr;
		return m_windowHandler->GetRenderer();
	}

	void ReEngine::Update()
	{
	}

	void ReEngine::PhysicsUpdate()
	{
	}
}
