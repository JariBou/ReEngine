#pragma once

#include <RealEngine/Core/Export.h>

namespace Re
{
	template<class T>
	class ReMasterPtr;

	template<class T>
	class RePtr
	{
		public:
			RePtr() = delete;
			RePtr(const RePtr& other) = delete;
			RePtr(const ReMasterPtr<T>& ptrHandler);
			RePtr(RePtr&&) = delete;
			~RePtr() = delete;

			T* Get();
			void Invalidate();

			RePtr& operator=(const RePtr&) = delete;
			RePtr& operator=(RePtr&&) = delete;

			T* operator-> ()
			{
				return m_objPtr;
			}

		private:
			T* m_objPtr;
	};
}

#include <RealEngine/Core/RePtr.inl>
