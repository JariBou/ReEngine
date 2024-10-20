#include <iostream>
#include <RealEngine/Renderer/WindowHandler.h>
#include <SDL2/SDL.h>

int main(int argc, char** argv) {
    
    Re::WindowInfo wi;
    wi.width = 680;
    wi.height = 480;

    Re::WindowHandler window (wi);
	//SDL_Window* m_window = SDL_CreateWindow("Title", wi.posX, wi.posY, wi.width, wi.height, SDL_WINDOW_SHOWN);
	//SDL_Renderer* m_renderer = SDL_CreateRenderer(m_window, 0, NULL);
	int mx0 = 0;
	int my0 = 0;
	int mx1 = 0;
	int my1 = 0;

    bool close = false;
    while (!close) {
		//SDL_RenderClear(m_renderer);

        SDL_Event event;
		while (window.PollEvent(event)) {
			switch (event.type)
			{
			case SDL_QUIT:
				close = true;
				break;
			case SDL_MOUSEBUTTONDOWN:
				mx0 = event.button.x;
				my0 = event.button.y;
				break;
			case SDL_MOUSEBUTTONUP:
				mx1 = event.button.x;
				my1 = event.button.y;

				window.SetColor(Re::RGBA(0, 0, 255, 255));
				//SDL_SetRenderDrawColor(window->GetRenderer(), 0, 0, 255, 255);
				SDL_Rect r{};
				r.x = mx0;
				r.y = my0;
				r.w = mx1 - mx0;
				r.h = my1 - my0;

				//SDL_RenderFillRect(window->GetRenderer(), &r);
				window.RenderRect(r);
				break;
			}
		}



		//SDL_RenderPresent(window->GetRenderer());
		window.UpdateRenderer();

        SDL_Delay(1000 / 60);
    }

	window.DestroyWindow();
	//SDL_DestroyWindow(m_window);
    // delete window;

    SDL_Quit();

    return 0;
}
