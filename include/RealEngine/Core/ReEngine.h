#pragma once

#include <RealEngine/Core/Export.h>
#include <RealEngine/Renderer/WindowHandler.h>
#include <RealEngine/Core/World.h>


namespace Re
{
	class KeyboardHandler;
}

namespace Re
{
	class SdlEventListener;

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
			inline const KeyboardHandler* GetKbHandler() const;

			void Start();
			void Stop() const;

#pragma region Ticks
			void PollEvents() const;
			void Tick();

			void Update();
			void PhysicsUpdate();
#pragma endregion
		
			void RegisterInputEventListener(SdlEventListener* inputReceiver);

		private:
			WindowHandler* m_windowHandler = nullptr;

			World* m_world;
			mutable bool isRunning;
		
			std::vector<SdlEventListener*> m_inputListeners;
			uint8_t m_targetFramerate = 60;

			KeyboardHandler* m_keyboardHandler;

	};

	
}

#include <RealEngine/Core/ReEngine.inl>
