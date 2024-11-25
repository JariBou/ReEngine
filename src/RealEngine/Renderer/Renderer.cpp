#include <iostream>
#include <RealEngine/Renderer/Renderer.h>
#include <SDL2/SDL.h>

#include "RealEngine/Renderer/WindowHandler.h"

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

    Renderer::Renderer(WindowHandler* windowHandler)
    {
        m_windowHandler = windowHandler;
        m_renderer = SDL_CreateRenderer(windowHandler->GetWindow(), -1, SDL_RENDERER_ACCELERATED);
        SDL_SetRenderDrawBlendMode(m_renderer, SDL_BLENDMODE_BLEND);
    }

    Renderer::~Renderer()
    {
        SDL_DestroyRenderer(m_renderer);
    }

    void Renderer::RenderClear()
    {
        SetColor(RGBA{.r= 0, .g= 0, .b= 0, .a= 0});
        //TODO: Resizable
        // for (size_t i = -1; i < m_renderLayers.size(); ++i)
        // {
        //     SDL_Texture* texture = m_renderLayers.at(static_cast<int>(i));
        //     SDL_DestroyTexture(texture);
        //     m_renderLayers.erase(static_cast<int>(i));
        // }
        for (auto& [_, renderText] : m_renderLayers)
        {
            SDL_SetRenderTarget(m_renderer, renderText);
            SDL_DestroyTexture(renderText);
            SDL_RenderClear(m_renderer);
        }
        ReverseColor();
        SetColor(RGBA::Black());
        SDL_SetRenderTarget(m_renderer, NULL);
        SDL_RenderClear(m_renderer);
        ReverseColor();
    }

    void Renderer::UpdateRenderer() const
    {
        for (auto& [_, renderText] : m_renderLayers)
        {
            SDL_RenderCopy(m_renderer, renderText, NULL, NULL);
        }
		SDL_RenderPresent(m_renderer);
	}

    void Renderer::RenderShape(Shape& shape, int layer)
    {
        SDL_Texture* targetTexture = GetTextureForLayer(layer);
        SDL_SetRenderTarget(m_renderer, targetTexture);
        shape.Render(this);
        SDL_SetRenderTarget(m_renderer, NULL);
    }

    void Renderer::RenderShape(Shape&& shape, int layer)
    {
        SDL_Texture* targetTexture = GetTextureForLayer(layer);
        SDL_SetRenderTarget(m_renderer, targetTexture);
        shape.Render(this);
        SDL_SetRenderTarget(m_renderer, NULL);
    }

    SDL_Texture* Renderer::GetTextureForLayer(int layer)
    {
        if (!m_renderLayers.contains(layer))
        {
            // int width;
            // int height;
            // SDL_GetWindowSize(m_windowHandler->GetWindow(), &width, &height);
            // std::cout << width << " | " << height << std::endl;
            
            SDL_Texture* texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_TARGET,
                                                      GetWindowInfo().width, GetWindowInfo().height);
            //TODO: create texture
            SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);
            m_renderLayers[layer] = texture;
        }
        
        return m_renderLayers[layer];
    }

    const FWindowInfo& Renderer::GetWindowInfo() const
    {
        return m_windowHandler->GetWindowInfo();
    }

    void Renderer::SetColor(const RGBA& color)
    {
		m_prevColor = m_currentColor;
		m_currentColor = color;
		SDL_SetRenderDrawColor(m_renderer, m_currentColor.r, m_currentColor.g, m_currentColor.b, m_currentColor.a);
	}

    void Renderer::SetColor(RGBA&& color)
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
