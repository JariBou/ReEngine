#pragma once

#include <RealEngine/Renderer/Export.h>

namespace Re
{
	class Renderer;

	struct RE_RENDERER_API Shape
	{
	public:
		int posX = 0;
		int posY = 0;
		
		virtual void Render(Renderer* renderer) = 0;

		virtual void Move(int dX, int dY)
		{
			posX += dX;
			posY += dY;
		}
	};
}


