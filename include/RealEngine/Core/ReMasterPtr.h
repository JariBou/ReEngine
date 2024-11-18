#pragma once

#include <memory>
#include <RealEngine/Core/Export.h>

#include "RePtrData.h"

namespace Re
{
	template<typename T>
	class ReMasterPtr
	{
		public:
			ReMasterPtr() = default;
			ReMasterPtr(const ReMasterPtr&) = delete;
			ReMasterPtr(ReMasterPtr&&) = delete;
			~ReMasterPtr();

		    T* GetObject();

			ReMasterPtr& operator=(const ReMasterPtr&) = delete;
			ReMasterPtr& operator=(ReMasterPtr&&) = delete;

		private:
			std::shared_ptr<RePtrData> m_data;
	};
}

#include <RealEngine/Core/ReMasterPtr.inl>
