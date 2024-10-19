#include <iostream>
#include <RealEngine/Renderer/WindowHandler.h>
#include <SDL_events.h>
#include <SDL_timer.h>
#include <SDL.h>

int main(int argc, char** argv) {
    
    Re::WindowInfo wi;
    wi.width = 680;
    wi.height = 480;

    Re::WindowHandler window(wi);
    int mx0, my0, mx1, my1;

    bool close = false;
    while (!close) {
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

				
				break;
            default:
                break;
            }
        }

        SDL_Delay(1000 / 60);
    }

    window.DestroyWindow();

    SDL_Quit();

    return 0;
}
