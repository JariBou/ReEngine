#pragma once

#include <RealEngine/Core/Export.h>
#include <RealEngine/Core/Components/ReComponent.h>

#ifndef TickFuncDef
#define inTickFunc void (T::*func)(/* maybe take in delta time in the future, idk */)
#define varTickFunc void (T::*m_tickFunc)(/* maybe take in delta time in the future, idk */)
#define TickFuncDef
#endif

namespace Re
{
	ReObjectTemplate
	class RCTickable : public ReComponent
	{
		public:
			RCTickable(ReObject* owner, inTickFunc);
			RCTickable(const RCTickable&) = delete;
			RCTickable(RCTickable&&) = delete;
			~RCTickable() override = default;

		    void TickComponent() override;

			RCTickable& operator=(const RCTickable&) = delete;
			RCTickable& operator=(RCTickable&&) = delete;

		private:
			varTickFunc;
	};
}

#include <RealEngine/Core/Components/RCTickable.inl>

#undef inTickFunc
#undef varTickFunc
