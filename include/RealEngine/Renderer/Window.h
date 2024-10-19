#pragma once
#include <SDL2/SDL_video.h>

class SDL_Window;

namespace Re
{
	struct WindowInfo {
		int width;
		int height;
		int posX = SDL_WINDOWPOS_UNDEFINED;
		int posY = SDL_WINDOWPOS_UNDEFINED;
	};

	class Window
	{
		public:
			Window(WindowInfo windowInfo);
			Window(const Window&) = delete;
			Window(Window&&) = delete;
			~Window() = default;

			Window& operator=(const Window&) = delete;
			Window& operator=(Window&&) = delete;

		private:
			SDL_Window* window;
	};
	
}
