#include <iostream>
#include <RealEngine/Renderer/WindowHandler.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_keycode.h>
#include <RealEngine/Core/ReEngine.h>
#include <RealEngine/Core/ReObject.h>

#include "RealEngine/Core/Components/RCDisplayable.h"
#include "RealEngine/Core/Components/RCTickable.h"
#include "RealEngine/Renderer/Shapes/Square.h"


class Tamere : public Re::ReObject {

public:

	Tamere(Re::ReEngine* engine) : ReObject(engine) {
		SetTags({"Tameres", "Autre Tag"});
	}

	void Print() {
		std::cout << "tamere" << "\n";
	}
};

class Tonpere : public Re::ReObject{
public:

	Re::Square square;

	Tonpere(Re::ReEngine* engine, Re::WindowHandler* inWindow, const std::string& inText) : ReObject(engine), square(0, 0, 10, 10, Re::RGBA::Red()) {
		text = inText;
		window = inWindow;
	}

	int testInt = 0;
	int testInt2 = 0;

	void RegisterComponents(std::vector<Re::ReComponent*>& componentList) override
	{
		componentList.push_back(Re::ReComponent::Create<Re::RCTickable<Tonpere>>(this, &Tonpere::TickFunc));
		//componentList.push_back(new Re::RCTickable(this, &Tonpere::TickFunc));
		
		componentList.push_back(Re::ReComponent::Create<Re::RCDisplayable<Tonpere>>(this, &Tonpere::DisplayFunc));

		ReObject::RegisterComponents(componentList);
	}

	void Move(int x, int y)
	{
		square.Move(x, y);
	}

	void TickFunc()
	{
		std::cout << "Tickable Tick Custom lol | " << testInt << "\n";
		testInt++;
	}

	void DisplayFunc(Re::Renderer* renderer)
	{
		std::cout << "RendererTick Custom lol" << "\n";
			
		renderer->RenderShape(square);
		renderer->RenderShape(Re::Square(0, 0, 10, 10, Re::RGBA::Blue()), 0);
		// renderer->SetColor(Re::RGBA{255, 0, 0, 255});
		// SDL_Rect rect{m_x, m_y, 10, 10};
		// renderer->RenderRect(rect);
		// renderer->ReverseColor();
	}

	void Print() {
		std::cout << text << "\n";
	}

private:
	std::string text;
	Re::WindowHandler* window;
};


int main(int argc, char** argv) {
    
    Re::FWindowInfo wi;
    wi.width = 680;
    wi.height = 480;

	Re::ReEngine engine;
	Re::WindowHandler* window = engine.InitWindow(wi);
	Re::Renderer* renderer = engine.GetRenderer();
	
	Re::RePtr<Re::ReObject> pTamere = engine.GetWorld()->InstantiateObject<Tamere>();
	Re::RePtr<Tonpere> pTamere2 = Re::RePtr<Tonpere>(pTamere);

	// Re::Shape* shape = new Re::Square(0, 0, 10, 10, Re::RGBA::Blue());

    for (auto element : pTamere->GetTags())
    {
	    std::cout << element << "\n";
    }
	pTamere->Destroy();

	Re::RePtr<Tonpere> pTonpere = engine.GetWorld()->InstantiateObject<Tonpere>(window, "Je suis un obj");

	if(pTamere.IsValid()) pTamere2->Print();

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
			case SDL_KEYDOWN:
				if (event.key.keysym.sym == SDLK_DOWN) {
					//delete pTamere;
					pTonpere->Move(0, 1);
				}else if (event.key.keysym.sym == SDLK_UP) {
					//delete pTamere;
					pTonpere->Move(0, -1);
				}else if (event.key.keysym.sym == SDLK_LEFT) {
					//delete pTamere;
					pTonpere->Move(-1, 0);
				}else if (event.key.keysym.sym == SDLK_RIGHT) {
					//delete pTamere;
					pTonpere->Move(1, 0);
				}
				break;
			}
		}



		//SDL_RenderPresent(window->GetRenderer());
		engine.Tick();

        SDL_Delay(1000 / 60);
    }

	window->DestroyWindow();
	//SDL_DestroyWindow(m_window);
    // delete window;

    SDL_Quit();

    return 0;
}
