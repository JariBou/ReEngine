#pragma once

#include <RealEngine/Core/Export.h>
#include <RealEngine/Renderer/WindowHandler.h>
#include <RealEngine/Core/World.h>


namespace Re
{
	class InputListener;

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
			Renderer* GetRenderer() const;
		
			inline World* GetWorld() const;

			void Start();

			void PollEvents() const;
			void Tick();

			void Update();
			void PhysicsUpdate();
		
			void RegisterInputEventListener(InputListener* inputReceiver);

		private:
			WindowHandler* m_windowHandler = nullptr;

			World* m_world;
			mutable bool isRunning;
		
			std::vector<InputListener*> m_inputListeners;

	};

	
}

#include <RealEngine/Core/ReEngine.inl>
