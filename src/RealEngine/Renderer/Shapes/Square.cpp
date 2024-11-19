#include <RealEngine/Renderer/Shapes/Square.h>

namespace Re
{
    Square::Square(int posX, int posY, int width, int height, RGBA color)
    {
        this->posX = posX;
        this->posY = posY;
        this->width = width;
        this->height = height;
        this->color = color;
    }

    Square::Square(int posX, int posY, int width, int height) : Square(posX, posY, width, height, RGBA::White())
    {
    }

    void Square::Render(Renderer* renderer)
    {
        renderer->SetColor(color);

        SDL_Rect rect{posX, posY, width, height};
        renderer->RenderRect(rect);
        
        renderer->ReverseColor();
    }
}
