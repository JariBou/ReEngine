#include <RealEngine/Core/Structs/Vector2f.h>

namespace Re
{
    Vector2f::Vector2f(float x, float y) : X(x), Y(y)
    {
    }

    Vector2f::Vector2f(const Vector2f& other) : X(other.X), Y(other.Y)
    {
    }

    Vector2f::Vector2f(Vector2f&& other) noexcept : X(other.X), Y(other.Y)
    {
    }
}
