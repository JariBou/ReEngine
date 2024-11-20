#include <RealEngine/Renderer/WindowHandler.h>
#include <SDL2/SDL.h>

namespace Re
{
	WindowHandler::WindowHandler(FWindowInfo windowInfo)
	{
		if (SDL_Init(SDL_INIT_EVERYTHING) < 0) throw;

		m_windowInfo = windowInfo;
		m_window = SDL_CreateWindow("Title", windowInfo.posX, windowInfo.posY, windowInfo.width, windowInfo.height, SDL_WINDOW_SHOWN);
		// SDL_SetWindowResizable(m_window, SDL_TRUE);
		m_renderer = new Renderer(this);
	}

	WindowHandler::~WindowHandler()
	{
		SDL_DestroyWindow(m_window);
	}

	void WindowHandler::DestroyWindow()
	{
		SDL_DestroyWindow(m_window);
		m_window = nullptr;
	}

	void WindowHandler::DestroyRenderer()
	{
		delete m_renderer;
		m_renderer = nullptr;
	}

	int WindowHandler::PollEvent(SDL_Event& event)
	{
		return SDL_PollEvent(&event);
	}

	SDL_Window* WindowHandler::GetWindow() const
	{
		return m_window;
	}

	const FWindowInfo& WindowHandler::GetWindowInfo() const
	{
		return m_windowInfo;
	}

	Renderer* WindowHandler::GetRenderer() const
	{
		return m_renderer;
	}
}
