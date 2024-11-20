#pragma once

#include <RealEngine/Core/Export.h>
#include <RealEngine/Renderer/WindowHandler.h>
#include <RealEngine/Core/World.h>


namespace Re
{
	class SdlEventListener;
	class KeyboardEventHandler;

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
			inline RePtr<KeyboardEventHandler> GetKbHandler() const;

			void Start();
			void Stop() const;

#pragma region Ticks
			void PollEvents() const;
			void Tick();

			void Update();
			void PhysicsUpdate();
#pragma endregion

		public:
			void SetNewKeyboardHandler(KeyboardEventHandler* handler);
					
			void RegisterInputEventListener(SdlEventListener* inputReceiver);
		
			void UnregisterInputEventListener(SdlEventListener* inputReceiver, bool autoDelete = true);

		private:
			WindowHandler* m_windowHandler = nullptr;

			World* m_world;
			mutable bool isRunning;
		
			std::vector<SdlEventListener*> m_inputListeners;
			uint8_t m_targetFramerate = 60;

			KeyboardEventHandler* m_keyboardHandler;

	};

	
}

#include <RealEngine/Core/ReEngine.inl>
