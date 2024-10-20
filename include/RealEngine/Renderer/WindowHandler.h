#pragma once

#include <SDL2/SDL_video.h>
#include <SDL2/SDL_events.h>
#include <RealEngine/Renderer/Export.h>
#include <RealEngine/Renderer/Renderer.h>

namespace Re
{
	struct RE_RENDERER_API WindowInfo {
		int width = 680;
		int height = 480;
		int posX = SDL_WINDOWPOS_UNDEFINED;
		int posY = SDL_WINDOWPOS_UNDEFINED;
	};

	class RE_RENDERER_API WindowHandler
	{
		public:
			WindowHandler(WindowInfo windowInfo);
			WindowHandler(const WindowHandler&) = delete;
			WindowHandler(WindowHandler&&) = delete;
			~WindowHandler() = default;

			WindowHandler& operator=(const WindowHandler&) = delete;
			WindowHandler& operator=(WindowHandler&&) = delete;

			void DestroyWindow();

			int PollEvent(SDL_Event& event);

			SDL_Window* GetWindow() const;
			Renderer* GetRenderer() const;

		private:
			SDL_Window* m_window;
			Renderer* m_renderer;
	};
	
}
