#include <RealEngine/Renderer/Window.h>
#include <SDL2/SDL.h>

namespace Re
{
	Window::Window(WindowInfo windowInfo)
	{
		if (SDL_Init(SDL_INIT_EVERYTHING) < 0) throw;

		window = SDL_CreateWindow("Title", windowInfo.posX, windowInfo.posY, windowInfo.width, windowInfo.height, SDL_WINDOW_SHOWN);
	}
}
