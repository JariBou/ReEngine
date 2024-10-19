#include <iostream>
#include <RealEngine/Renderer/WindowHandler.h>
#include <SDL2/SDL.h>

int main(int argc, char** argv) {
    
    Re::WindowInfo wi;
    wi.width = 680;
    wi.height = 480;

    Re::WindowHandler* window = new Re::WindowHandler(wi);

    bool close = false;
    while (!close) {
        SDL_Event event;
		while (SDL_PollEvent(&event)) {
			switch (event.type)
			{
			case SDL_QUIT:
				close = true;
				break;
			}
		}

        SDL_Delay(1000 / 60);
    }

    window->DestroyWindow();
    delete window;

    SDL_Quit();

    return 0;
}
