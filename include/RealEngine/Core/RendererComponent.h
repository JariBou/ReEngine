#pragma once

#include <RealEngine/Core/Export.h>

namespace Re
{
	class Renderer;

	class RE_CORE_API RendererComponent
	{
		public:
			virtual void Render(Renderer* Renderer) = 0;
	};
}


