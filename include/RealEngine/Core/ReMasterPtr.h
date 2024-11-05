#pragma once

#include <RealEngine/Core/Export.h>
#include <vector>
#include <RealEngine/Core/RePtr.h>

namespace Re
{

	template<class T>
	class RE_CORE_API ReMasterPtr
	{
		public:
			ReMasterPtr(T* ptr) : m_objPtr(ptr) {}
			ReMasterPtr(const ReMasterPtr&) = delete;
			ReMasterPtr(ReMasterPtr&& other);
			~ReMasterPtr();

			T* Get();

			ReMasterPtr& operator=(const ReMasterPtr&) = delete;
			ReMasterPtr& operator=(ReMasterPtr&& other);

			T* operator-> ()
			{
				return m_objPtr;
			}

		private:
			T* m_objPtr;
			std::vector<class RePtr<T>*> m_referencingObjects;

			friend class RePtr<T>;
	};
}

#include <RealEngine/Core/ReMasterPtr.inl>
