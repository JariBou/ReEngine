#pragma once

#include <RealEngine/Renderer/Export.h>
#include <SDL2/SDL_video.h>

class SDL_Renderer;
class SDL_Rect;

namespace Re
{
	struct RE_RENDERER_API RGBA {
		int r = 0;
		int g = 0;
		int b = 0;
		int a = 255;
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

			void RenderClear() const;
			void UpdateRenderer() const;

			void SetColor(RGBA color);
			void ReverseColor();
			RGBA GetCurrentColor() const;

			void RenderRect(SDL_Rect& rect);

		private:
			SDL_Renderer* m_renderer;

			RGBA m_currentColor;
			RGBA m_prevColor;
	};
}
