#pragma once

#include <RealEngine/Core/Export.h>
#include <utility>

namespace Re
{
	template<class T>
	class RE_CORE_API ReSharedPtr
	{
		public:
			ReSharedPtr(T* ptr) : m_objPtr(ptr){
				m_counter = new unsigned int(1);
			}

			ReSharedPtr(const ReSharedPtr& other) : m_objPtr(other.m_objPtr), m_counter(other.m_counter) {
				(*m_counter)++;
			}

			ReSharedPtr(ReSharedPtr&& other) : m_objPtr(other.m_objPtr), m_counter(other.m_counter) {
				other.m_objPtr = nullptr;
				other.m_counter = nullptr;
			}

			~ReSharedPtr() {
				reset();
			}

			void reset()
			{
				if (!m_counter)
					return;

				(*m_counter)--;
				if (*m_counter == 0)
				{
					delete m_objPtr;
					delete m_counter;
				}
			}

			ReSharedPtr& operator=(const ReSharedPtr& other) {
				reset();

				m_objPtr = other.m_objPtr;
				m_counter = other.m_counter;
				(*m_counter)++;
			}

			ReSharedPtr& operator=(ReSharedPtr&& other) {
				std::swap(m_objPtr, other.m_objPtr);
				std::swap(m_counter, other.m_counter);
				return *this;
			}

		private:
			T* m_objPtr;
			unsigned int* m_counter;
	};
}


