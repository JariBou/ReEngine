#include <iostream>
#include <RealEngine/Renderer/WindowHandler.h>
#include <SDL2/SDL.h>

int main(int argc, char** argv) {
    
    Re::WindowInfo wi;
    wi.width = 680;
    wi.height = 480;

    Re::WindowHandler* window = new Re::WindowHandler(wi);

	int mx0 = 0;
	int my0 = 0;
	int mx1 = 0;
	int my1 = 0;

    bool close = false;
    while (!close) {
		window->RenderClear();

        SDL_Event event;
		while (SDL_PollEvent(&event)) {
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

				SDL_SetRenderDrawColor(window->GetRenderer(), 0, 0, 255, 255);
				SDL_Rect r{};
				r.x = mx0;
				r.y = my0;
				r.w = mx1 - mx0;
				r.h = my1 - my0;

				SDL_RenderFillRect(window->GetRenderer(), &r);
				break;
			}
		}



        window->UpdateRenderer();

        SDL_Delay(1000 / 60);
    }

    window->DestroyWindow();
    delete window;

    SDL_Quit();

    return 0;
}
