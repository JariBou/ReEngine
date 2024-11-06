#pragma once

#include <RealEngine/Core/Export.h>
#include <vector>
#include <RealEngine/Core/RePtr.h>

namespace Re
{
	
	template<class T>
	class ReMasterPtr
	{
		public:
			ReMasterPtr();
			ReMasterPtr(const ReMasterPtr&) = delete;
			ReMasterPtr(ReMasterPtr&& other) noexcept;
			~ReMasterPtr();

			template<std::derived_from<T> U>
			ReMasterPtr(ReMasterPtr<U>& other);

			template<std::derived_from<T> U>
			ReMasterPtr(ReMasterPtr<U>&& other);

			T* Get();

			ReMasterPtr& operator=(const ReMasterPtr&) = delete;
			ReMasterPtr& operator=(ReMasterPtr&& other) noexcept;

			T* operator-> ()
			{
				return m_objPtr;
			}

		private:
			T* m_objPtr;
			mutable std::vector<RePtrBase*> m_referencingObjects;

			void Register(RePtrBase* item) const;
			void Unregister(RePtrBase* item) const;

		friend class RePtr<T>;

		template<typename U>
		friend class ReMasterPtr;
	};


}

#include <RealEngine/Core/ReMasterPtr.inl>
