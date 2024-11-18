#pragma once

#include <RealEngine/Core/Export.h>

namespace Re
{
	class ReEngine;
	class ReObject;

	class RE_CORE_API ReComponent
	{
		public:
		ReComponent(ReObject* Owner);
		virtual ~ReComponent() = default;
		
		virtual void ComponentTick(ReEngine* Engine) = 0;

			ReObject* GetOwner() const { return m_owner; }
			
		protected:
		    ReObject* m_owner;
	};
}


