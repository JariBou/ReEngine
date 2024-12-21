#include <iostream>
#include <RealEngine/Renderer/WindowHandler.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_keycode.h>
#include <RealEngine/Core/ReEngine.h>
#include <RealEngine/Core/ReObject.h>
#include <RealEngine/Core/Physics/Quadtree.h>

#include "RealEngine/Core/Components/RCDisplayable.h"
#include "RealEngine/Core/Components/RCSdlEventReceiver.h"
#include "RealEngine/Core/Components/RCTickable.h"
#include "RealEngine/Core/Inputs/KeyboardHandler.h"
#include "RealEngine/Renderer/Shapes/Square.h"


class Mom : public Re::ReObject {

public:

	Mom(Re::ReEngine* engine) : ReObject(engine) {
		SetTags({"A Tag", "Another Tag"});
	}

	void Print() {
		std::cout << "Mom print" << "\n";
	}
};

class Dad : public Re::ReObject{
public:
	

	Re::Square square;

	Dad(Re::ReEngine* engine, Re::WindowHandler* inWindow, const std::string& inText) : ReObject(engine), square(0, 0, 10, 10, Re::RGBA::Red()) {
		text = inText;
		window = inWindow;
	}

	int testInt = 0;
	int testInt2 = 0;

	void RegisterComponents(std::vector<Re::ReComponent*>& componentList) override
	{
		using namespace Re;
		componentList.push_back(ReComponent::Create<RCTickable<Dad>>(this, &Dad::TickFunc));
		//componentList.push_back(new Re::RCTickable(this, &Tonpere::TickFunc));
		
		componentList.push_back(ReComponent::Create<RCDisplayable<Dad>>(this, &Dad::DisplayFunc));
		
		//componentList.push_back(Re::ReComponent::Create<Re::RCSdlEventReceiver<Tonpere>>(this, &Tonpere::InputEventFunc));

		ReObject::RegisterComponents(componentList);
	}

	void Move(int x, int y)
	{
		square.Move(x, y);
	}

	void TickFunc()
	{
		Move(GetEngine()->GetKbHandler()->GetAxis<int>(Re::KB_AxisName::Horizontal), GetEngine()->GetKbHandler()->GetAxis<int>(Re::KB_AxisName::Vertical));
		
		//std::cout << "Tickable Tick Custom lol | " << testInt << "\n";
		
		testInt++;
	}

	void DisplayFunc(Re::Renderer* renderer)
	{
		//std::cout << "RendererTick Custom lol" << "\n";
			
		renderer->RenderShape(square);
		renderer->RenderShape(Re::Square(0, 0, 10, 10, Re::RGBA::Blue()), 0);
		// renderer->SetColor(Re::RGBA{255, 0, 0, 255});
		// SDL_Rect rect{m_x, m_y, 10, 10};
		// renderer->RenderRect(rect);
		// renderer->ReverseColor();
	}

	void InputEventFunc(SDL_Event& event)
	{
		event.key.state = SDL_PRESSED or SDL_RELEASED;
		switch (event.type)
		{
		case SDL_KEYDOWN:
			if (event.key.keysym.sym == SDLK_DOWN) {
				Move(0, 1);
			}else if (event.key.keysym.sym == SDLK_UP) {
				Move(0, -1);
			}else if (event.key.keysym.sym == SDLK_LEFT) {
				Move(-1, 0);
			}else if (event.key.keysym.sym == SDLK_RIGHT) {
				Move(1, 0);
			}
			break;
		}
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
	
	Re::RePtr<Re::ReObject> pMomAsObj = engine.GetWorld()->InstantiateObject<Mom>();
	Re::RePtr<Dad> pDadFromMom = Re::RePtr<Dad>(pMomAsObj);

	std::remove_reference<int>::type;

	// Re::Shape* shape = new Re::Square(0, 0, 10, 10, Re::RGBA::Blue());

    for (auto element : pMomAsObj->GetTags())
    {
	    std::cout << element << "\n";
    }

	Re::Quadtree quadTree = Re::Quadtree(2);
	quadTree.AddObject(pMomAsObj);

	Re::RePtr<Dad> pDad = engine.GetWorld()->InstantiateObject<Dad>(window, "Text as constructor argument");
	quadTree.AddObject(pDad);

	if(pMomAsObj.IsValid()) pDadFromMom->Print();

	if (pDad.IsValid()) pDad->Print();

	engine.Start();

	window->DestroyWindow();
	//SDL_DestroyWindow(m_window);
    // delete window;

    SDL_Quit();

    return 0;
}
