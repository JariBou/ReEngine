#include <RealEngine/Renderer/Renderer.h>
#include <SDL2/SDL.h>

namespace Re
{
    Renderer::Renderer(SDL_Window* window)
    {
        m_renderer = SDL_CreateRenderer(window, 0, NULL);
    }

    void Renderer::RenderClear() const
    {
        SDL_RenderClear(m_renderer);
    }

    void Renderer::UpdateRenderer() const
    {
		SDL_RenderPresent(m_renderer);
	}

    void Renderer::SetColor(RGBA color)
    {
		m_prevColor = m_currentColor;
		m_currentColor = color;
		SDL_SetRenderDrawColor(m_renderer, m_currentColor.r, m_currentColor.g, m_currentColor.b, m_currentColor.a);
	}
    void Renderer::ReverseColor()
    {
		m_currentColor = m_prevColor;
		SDL_SetRenderDrawColor(m_renderer, m_currentColor.r, m_currentColor.g, m_currentColor.b, m_currentColor.a);
	}
    RGBA Renderer::GetCurrentColor() const
    {
        return m_currentColor;
    }

    void Renderer::RenderRect(SDL_Rect& rect)
    {
        SDL_RenderFillRect(m_renderer, &rect);
    }
}
