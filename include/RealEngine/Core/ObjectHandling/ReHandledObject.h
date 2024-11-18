#pragma once

#include <RealEngine/Core/Export.h>
#include <RealEngine/Core/ObjectHandling/ReHandleData.h>

namespace Re
{
	template<typename T> class RePtr;

	template <typename T>
	class ReHandledObject
	{
		friend class RePtr<T>;
		
		public:
			ReHandledObject() = default;
			ReHandledObject(const ReHandledObject&) = delete;
			ReHandledObject(ReHandledObject&&) = delete;
			virtual ~ReHandledObject();

			std::shared_ptr<const ReHandleData> GetData();

			ReHandledObject& operator=(const ReHandledObject&) = delete;
			ReHandledObject& operator=(ReHandledObject&&) = delete;

		protected:
			void UnregisterAllHandles() noexcept;

		private:
			void InitHandleData();
		
			std::shared_ptr<ReHandleData> m_handleData;
	};
}

#include <RealEngine/Core/ObjectHandling/ReHandledObject.inl>
