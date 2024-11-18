#pragma once

#include <RealEngine/Core/Export.h>

#include <memory>
#include <RealEngine/Core/RePtrData.h>

namespace Re
{
	template<typename T>
	class ReMasterPtr
	{
		public:
			template<typename ...Args>
			ReMasterPtr(Args&&... constructorParams);
		
			ReMasterPtr(const ReMasterPtr&) = delete;
			ReMasterPtr(ReMasterPtr&& other) noexcept;
			~ReMasterPtr();

		    T* GetObject();

			void Reset(T* object);

			std::shared_ptr<const RePtrData> GetData() const;

			ReMasterPtr& operator=(const ReMasterPtr&) = delete;
			ReMasterPtr& operator=(ReMasterPtr&&) = delete;

		private:
			std::shared_ptr<RePtrData> m_data;
	};
}

#include <RealEngine/Core/ReMasterPtr.inl>
