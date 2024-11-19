#pragma once

#include <map>
#include <SDL_render.h>
#include <RealEngine/Renderer/Export.h>
#include <SDL2/SDL_video.h>
#include "Shapes/Shape.h"

namespace Re
{
	struct FWindowInfo;
	class WindowHandler;

	struct RE_RENDERER_API RGBA {
		uint8_t r = 0;
		uint8_t g = 0;
		uint8_t b = 0;
		uint8_t a = 255;
		
		static RGBA Black();
		static RGBA Red();
		static RGBA White();
		static RGBA Blue();
	};

	class RE_RENDERER_API Renderer
	{
		public:
			explicit Renderer(WindowHandler* windowHandler);
			Renderer(const Renderer&) = delete;
			Renderer(Renderer&&) = delete;
			~Renderer();

			Renderer& operator=(const Renderer&) = delete;
			Renderer& operator=(Renderer&&) = delete;

			void RenderClear();
			void UpdateRenderer() const;
			void RenderShape(Shape& shape, int layer = -1);
			void RenderShape(Shape&& shape, int layer = -1);

			SDL_Texture* GetTextureForLayer(int layer);

			const FWindowInfo& GetWindowInfo() const;

			void SetColor(const RGBA& color);
			void SetColor(RGBA&& color);
			void ReverseColor();
			RGBA GetCurrentColor() const;

			void RenderRect(SDL_Rect& rect) const;

		private:
			SDL_Renderer* m_renderer;
			WindowHandler* m_windowHandler;
		
			std::map<int, SDL_Texture*> m_renderLayers;

			RGBA m_currentColor;
			RGBA m_prevColor;
	};
}
