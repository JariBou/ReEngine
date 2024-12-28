#pragma once

#include <RealEngine/Core/Export.h>

namespace Re
{
	struct RE_CORE_API Vector2f
	{
		public:
			Vector2f(float x, float y);
			Vector2f(const Vector2f& other);
			Vector2f(Vector2f&& other) noexcept;
			~Vector2f() = default;

			Vector2f& operator=(const Vector2f&) = default;
			Vector2f& operator=(Vector2f&&) noexcept = default;

			float X;
			float Y;
	};
}


