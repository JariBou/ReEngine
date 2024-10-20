#include <RealEngine/Renderer/WindowHandler.h>
#include <SDL2/SDL.h>

namespace Re
{
	WindowHandler::WindowHandler(WindowInfo windowInfo)
	{
		if (SDL_Init(SDL_INIT_EVERYTHING) < 0) throw;

		m_window = SDL_CreateWindow("Title", windowInfo.posX, windowInfo.posY, windowInfo.width, windowInfo.height, SDL_WINDOW_SHOWN);
		m_renderer = SDL_CreateRenderer(m_window, 0, NULL);
	}

	void WindowHandler::DestroyWindow()
	{
		SDL_DestroyWindow(m_window);
	}

	void WindowHandler::RenderClear() const
	{
		SDL_RenderClear(m_renderer);
	}

	void WindowHandler::UpdateRenderer() const
	{
		SDL_RenderPresent(m_renderer);
	}

	int WindowHandler::PollEvent(SDL_Event& event)
	{
		return SDL_PollEvent(&event);
	}

	void WindowHandler::SetColor(RGBA color)
	{
		m_prevColor = m_currentColor;
		m_currentColor = color;
		SDL_SetRenderDrawColor(m_renderer, m_currentColor.r, m_currentColor.g, m_currentColor.b, m_currentColor.a);
	}

	void WindowHandler::ReverseColor()
	{
		m_currentColor = m_prevColor;
		SDL_SetRenderDrawColor(m_renderer, m_currentColor.r, m_currentColor.g, m_currentColor.b, m_currentColor.a);
	}

	void WindowHandler::RenderRect(SDL_Rect& rect)
	{
		SDL_RenderFillRect(m_renderer, &rect);
	}

	SDL_Window* WindowHandler::GetWindow() const
	{
		return m_window;
	}

	SDL_Renderer* WindowHandler::GetRenderer() const
	{
		return m_renderer;
	}
	RGBA WindowHandler::GetCurrentColor() const
	{
		return m_currentColor;
	}
}
