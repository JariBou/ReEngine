#pragma once

#include <SDL2/SDL_video.h>
#include <RealEngine/Renderer/Export.h>

class SDL_Window;
class SDL_Renderer;

namespace Re
{
	struct RE_RENDERER_API WindowInfo {
		int width = 680;
		int height = 480;
		int posX = SDL_WINDOWPOS_UNDEFINED;
		int posY = SDL_WINDOWPOS_UNDEFINED;
	};

	struct RE_RENDERER_API RGBA {
		int r = 0;
		int g = 0;
		int b = 0;
		int a = 255;
	};

	class RE_RENDERER_API WindowHandler
	{
		public:
			WindowHandler(WindowInfo windowInfo);
			WindowHandler(const WindowHandler&) = delete;
			WindowHandler(WindowHandler&&) = delete;
			~WindowHandler() = default;

			WindowHandler& operator=(const WindowHandler&) = delete;
			WindowHandler& operator=(WindowHandler&&) = delete;

			void DestroyWindow();
			
			void UpdateRenderer() const;
			
			void SetTempColor(RGBA color);
			void ReverseColor();

			RGBA GetCurrentColor() const;

			SDL_Window* GetWindow() const;
			SDL_Renderer* GetRenderer() const;

		private:
			RGBA m_currentColor;
			RGBA m_prevColor;
			SDL_Window* m_window;
			SDL_Renderer* m_renderer;
	};
	
}
