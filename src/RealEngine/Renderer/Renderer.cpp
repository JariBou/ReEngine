#include <RealEngine/Renderer/Renderer.h>
#include <SDL2/SDL.h>

namespace Re
{
    RGBA RGBA::Black()
    {
        return RGBA{.r= 0, .g= 0, .b= 0, .a= 255};
    }

    RGBA RGBA::Red()
    {
        return RGBA{.r= 255, .g= 0, .b= 0, .a= 255};
    }

    RGBA RGBA::White()
    {
        return RGBA{.r= 255, .g= 255, .b= 255, .a= 255};
    }

    RGBA RGBA::Blue()
    {
        return RGBA{.r= 0, .g= 0, .b= 255, .a= 255};
    }

    Renderer::Renderer(SDL_Window* window)
    {
        m_renderer = SDL_CreateRenderer(window, 0, NULL);
    }

    void Renderer::RenderClear()
    {
        SetColor(RGBA::Black());
        SDL_RenderClear(m_renderer);
        ReverseColor();
    }

    void Renderer::UpdateRenderer() const
    {
		SDL_RenderPresent(m_renderer);
	}

    void Renderer::RenderShape(Shape& shape)
    {
        shape.Render(this);
    }

    void Renderer::RenderShape(Shape&& shape)
    {
        shape.Render(this);
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

    void Renderer::RenderRect(SDL_Rect& rect) const
    {
        SDL_RenderFillRect(m_renderer, &rect);
    }
}
