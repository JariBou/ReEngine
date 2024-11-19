#pragma once

#include <RealEngine/Renderer/Export.h>
#include <SDL2/SDL_video.h>

#include "Shapes/Shape.h"

class SDL_Renderer;

namespace Re
{
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
			Renderer(SDL_Window* window);
			Renderer(const Renderer&) = delete;
			Renderer(Renderer&&) = delete;
			~Renderer() = default;

			Renderer& operator=(const Renderer&) = delete;
			Renderer& operator=(Renderer&&) = delete;

			void RenderClear();
			void UpdateRenderer() const;
			void RenderShape(Shape& shape);
			void RenderShape(Shape&& shape);

			void SetColor(RGBA color);
			void ReverseColor();
			RGBA GetCurrentColor() const;

			void RenderRect(SDL_Rect& rect) const;

		private:
			SDL_Renderer* m_renderer;

			RGBA m_currentColor;
			RGBA m_prevColor;
	};
}
