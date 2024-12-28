#include <RealEngine/Core/Structs/Vector2i.h>

namespace Re
{
    Vector2i::Vector2i(int x, int y) : X(x), Y(y)
    {
    }

    Vector2i::Vector2i(const Vector2i& other) : X(other.X), Y(other.Y)
    {
    }

    Vector2i::Vector2i(Vector2i&& other) noexcept : X(other.X), Y(other.Y)
    {
    }
}
