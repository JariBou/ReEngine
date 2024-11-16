#pragma once

#include <RealEngine/Core/Export.h>

namespace Re
{
	class ReMasterPtrBase;

	class RePtrBase {
	public:
		virtual void Invalidate() = 0;
		virtual void PassNewMaster(ReMasterPtrBase* master) = 0;
	};
	
	class ReMasterPtrBase {
	public: 
		virtual void Register(RePtrBase* item) const = 0;
		virtual void Unregister(RePtrBase* item) const = 0;
	};
	
	
}


