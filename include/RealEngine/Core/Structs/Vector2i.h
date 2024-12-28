#pragma once

#include <RealEngine/Core/Export.h>

namespace Re
{
	class RE_CORE_API Vector2i
	{
		public:
			Vector2i(int x, int y);
			Vector2i(const Vector2i& other);
			Vector2i(Vector2i&& other) noexcept;
			~Vector2i() = default;

			Vector2i& operator=(const Vector2i&) = default;
			Vector2i& operator=(Vector2i&&) = default;

			int X;
			int Y;
	};
}


