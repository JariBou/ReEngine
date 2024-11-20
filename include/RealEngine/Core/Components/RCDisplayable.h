#pragma once

#include <RealEngine/Core/Export.h>

#include "ReComponent.h"

#ifndef DisplayFuncDef
// namespace Re
// {
// 	class Renderer;
// }
#define inDisplayFunc void (T::*func)(Renderer* /* maybe take in delta time in the future, idk */)
#define varDisplayFunc void (T::*m_displayFunc)(Renderer*/* maybe take in delta time in the future, idk */)
#define DisplayFuncDef
#endif

namespace Re
{
	class Renderer;
	
	ReObjectTemplate
	class RCDisplayable : public ReComponent
	{
		public:
			RCDisplayable(ReObject* owner, inDisplayFunc);
			RCDisplayable(const RCDisplayable&) = delete;
			RCDisplayable(RCDisplayable&&) = delete;
			~RCDisplayable() override = default;
		
			void TickComponent() override;

			RCDisplayable& operator=(const RCDisplayable&) = delete;
			RCDisplayable& operator=(RCDisplayable&&) = delete;

		private:
			varDisplayFunc;
	};

	
}

#include <RealEngine/Core/Components/RCDisplayable.inl>

#undef inDisplayFunc
#undef varDisplayFunc

