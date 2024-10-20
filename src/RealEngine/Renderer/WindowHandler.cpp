#include <RealEngine/Renderer/WindowHandler.h>
#include <SDL2/SDL.h>

namespace Re
{
	WindowHandler::WindowHandler(WindowInfo windowInfo)
	{
		if (SDL_Init(SDL_INIT_EVERYTHING) < 0) throw;

		m_window = SDL_CreateWindow("Title", windowInfo.posX, windowInfo.posY, windowInfo.width, windowInfo.height, SDL_WINDOW_SHOWN);
		m_renderer = new Renderer(m_window);
	}

	void WindowHandler::DestroyWindow()
	{
		SDL_DestroyWindow(m_window);
	}

	int WindowHandler::PollEvent(SDL_Event& event)
	{
		return SDL_PollEvent(&event);
	}

	SDL_Window* WindowHandler::GetWindow() const
	{
		return m_window;
	}

	Renderer* WindowHandler::GetRenderer() const
	{
		return m_renderer;
	}
}
