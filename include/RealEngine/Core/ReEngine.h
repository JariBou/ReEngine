#pragma once

#include <RealEngine/Core/Export.h>
#include <RealEngine/Renderer/WindowHandler.h>
#include <RealEngine/Core/World.h>


namespace Re
{

	class RE_CORE_API ReEngine
	{
		public:
			ReEngine();
			ReEngine(const ReEngine&) = delete;
			ReEngine(ReEngine&&) = delete;
			~ReEngine() = default;

			ReEngine& operator=(const ReEngine&) = delete;
			ReEngine& operator=(ReEngine&&) = delete;

			WindowHandler* InitWindow(FWindowInfo wi);
			Renderer* GetRenderer();

			inline World* GetWorld();

			void Tick();

			void Update();
			void PhysicsUpdate();

		private:
			WindowHandler* m_windowHandler = nullptr;

			World* m_world;
	};
}
