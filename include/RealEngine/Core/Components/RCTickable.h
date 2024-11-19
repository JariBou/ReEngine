#pragma once

#include <RealEngine/Core/Export.h>

#include "ReComponent.h"
#include <RealEngine/Core/ReObject.h>

class Tonpere;

namespace Re
{
	template<typename T>
	class RCTickable : public ReComponent
	{
		public:
			RCTickable(ReObject* owner, void (T::*func)(/* maybe take in delta time in the future, idk */));
			RCTickable(const RCTickable&) = delete;
			RCTickable(RCTickable&&) = delete;
			~RCTickable() override = default;

		    void TickComponent() override;

			RCTickable& operator=(const RCTickable&) = delete;
			RCTickable& operator=(RCTickable&&) = delete;

		private:
			void (T::*m_tickFunc)();
	};
}

#include <RealEngine/Core/Components/RCTickable.inl>
