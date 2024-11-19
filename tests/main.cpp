#include <iostream>
#include <RealEngine/Renderer/WindowHandler.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_keycode.h>
#include <RealEngine/Core/ReEngine.h>
#include <RealEngine/Core/ReObject.h>

#include "RealEngine/Core/Components/RCTickable.h"


class Tamere : public Re::ReObject {

public:

	Tamere(Re::ReEngine* engine) : ReObject(engine) {
	}

	void Print() {
		std::cout << "tamere" << "\n";
	}
};

class Tonpere : public Re::ReObject{
public:

	Tonpere(Re::ReEngine* engine, Re::WindowHandler* inWindow, const std::string& inText) : ReObject(engine) {
		text = inText;
		window = inWindow;
	}

	int testInt = 0;

	void RegisterComponents(std::vector<Re::ReComponent*>& componentList) override
	{
		componentList.push_back(Re::ReComponent::Create<Re::RCTickable<Tonpere>>(this, &Tonpere::TickFunc));
		//componentList.push_back(new Re::RCTickable(this, &Tonpere::TickFunc));

		ReObject::RegisterComponents(componentList);
	}

	void TickFunc()
	{
		std::cout << "Tickable Tick Custom lol | " << testInt << "\n";
		testInt++;
	}

	void Print() {
		std::cout << text << "\n";
	}

private:
	std::string text;
	Re::WindowHandler* window;
};


int main(int argc, char** argv) {
    
    Re::WindowInfo wi;
    wi.width = 680;
    wi.height = 480;

	Re::ReEngine engine;
	Re::WindowHandler* window = engine.InitWindow(wi);
	Re::Renderer* renderer = engine.GetRenderer();

    //Re::WindowHandler window (wi);
	//SDL_Window* m_window = SDL_CreateWindow("Title", wi.posX, wi.posY, wi.width, wi.height, SDL_WINDOW_SHOWN);
	//SDL_Renderer* m_renderer = SDL_CreateRenderer(m_window, 0, NULL);
	int mx0 = 0;
	int my0 = 0;
	int mx1 = 0;
	int my1 = 0;

	// pTamere est bien initialis�
	Re::RePtr<Tamere> pTamere = engine.GetWorld()->InstantiateObject<Tamere>();
	// pTamere devient null, pTamere2 est bien initialis�???
	// ok non alors le pb est dans InstantiateObject ou lors du return un ReMasterPtr est détruit et donc invalide les RePtr
	Re::RePtr<Tamere> pTamere2 = Re::RePtr<Tamere>(pTamere);

	Re::RePtr<Tonpere> pTonpere = engine.GetWorld()->InstantiateObject<Tonpere>(window, "Je suis un obj");
	//Re::RePtr<Re::ReObject> pTamere4 = Re::RePtr(pTamere3);
	
	// CA PRINT ALORS QUE C'EST NULL?????
	// ça explique tjrs pas ça tho...
	// Ok alors en fait c'est convertit en "extensions C#" avec le this en param donc tant que tu touches pas au truc c'est fine
	if(pTamere.IsValid()) pTamere->Print();

	if (pTonpere.IsValid()) pTonpere->Print();

    bool close = false;
    while (!close) {
		//SDL_RenderClear(m_renderer);

        SDL_Event event;
		while (window->PollEvent(event)) {
			switch (event.type)
			{
			case SDL_QUIT:
				close = true;
				break;
			case SDL_MOUSEBUTTONDOWN:
				mx0 = event.button.x;
				my0 = event.button.y;
				break;
			case SDL_KEYDOWN:
				if (event.key.type == SDLK_a) {
					//delete pTamere;
				}
				break;
			case SDL_MOUSEBUTTONUP:
				mx1 = event.button.x;
				my1 = event.button.y;

				renderer->SetColor(Re::RGBA(0, 0, 255, 255));
				//SDL_SetRenderDrawColor(window->GetRenderer(), 0, 0, 255, 255);
				SDL_Rect r{};
				r.x = mx0;
				r.y = my0;
				r.w = mx1 - mx0;
				r.h = my1 - my0;

				//SDL_RenderFillRect(window->GetRenderer(), &r);
				renderer->RenderRect(r);
				break;
			
			}
		}



		//SDL_RenderPresent(window->GetRenderer());
		engine.Tick();
		renderer->UpdateRenderer();

        SDL_Delay(1000 / 60);
    }

	window->DestroyWindow();
	//SDL_DestroyWindow(m_window);
    // delete window;

    SDL_Quit();

    return 0;
}
