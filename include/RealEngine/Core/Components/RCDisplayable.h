#pragma once

#include <RealEngine/Core/Export.h>

#include "ReComponent.h"

#ifndef DisplayFuncDef
#define inDisplayFunc void (T::*func)(/* maybe take in delta time in the future, idk */)
#define varDisplayFunc void (T::*m_displayFunc)(/* maybe take in delta time in the future, idk */)
#define DisplayFuncDef
#endif

namespace Re
{
	ReObjectTemplate
	class RE_CORE_API RCDisplayable : public ReComponent
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

