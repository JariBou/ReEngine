#pragma once

#include <RealEngine/Core/Export.h>
#include <RealEngine/Renderer/WindowHandler.h>

namespace Re
{
	class RE_CORE_API ReEngine
	{
		public:
			ReEngine() = default;
			ReEngine(const ReEngine&) = delete;
			ReEngine(ReEngine&&) = delete;
			~ReEngine() = default;

			ReEngine& operator=(const ReEngine&) = delete;
			ReEngine& operator=(ReEngine&&) = delete;

			WindowHandler* InitWindow(WindowInfo wi);
			Renderer* GetRenderer();

			void Update();
			void PhysicsUpdate();

		private:
			WindowHandler* m_windowHandler = nullptr;
	};
}
