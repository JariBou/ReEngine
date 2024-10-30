#pragma once

#include <RealEngine/Core/Export.h>
#include <RealEngine/Renderer/WindowHandler.h>


namespace Re
{
	class World;

	class RE_CORE_API ReEngine
	{
		public:
			ReEngine();
			ReEngine(const ReEngine&) = delete;
			ReEngine(ReEngine&&) = delete;
			~ReEngine() = default;

			ReEngine& operator=(const ReEngine&) = delete;
			ReEngine& operator=(ReEngine&&) = delete;

			WindowHandler* InitWindow(WindowInfo wi);
			Renderer* GetRenderer();

			World* GetWorld();

			void Update();
			void PhysicsUpdate();

		private:
			WindowHandler* m_windowHandler = nullptr;

			World* m_world;
	};
}
