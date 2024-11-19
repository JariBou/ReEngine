#pragma once

#include <RealEngine/Renderer/Export.h>

#include "Shape.h"
#include "RealEngine/Renderer/Renderer.h"

namespace Re
{
	struct RE_RENDERER_API Square : public Shape
	{
		int width = 0;
		int height = 0;
		RGBA color = RGBA::Black();

		Square(int posX, int posY, int width, int height, RGBA color);
		

		Square(int posX, int posY, int width, int height);
		
		public:
			void Render(Renderer* renderer) override;

		

		private:
	};
}


