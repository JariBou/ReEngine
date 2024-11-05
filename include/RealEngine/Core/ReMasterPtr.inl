#pragma once

namespace Re
{
	template<class T>
	T* ReMasterPtr<T>::Get()
	{
		return m_objPtr;
	}

	template <class T>
	ReMasterPtr<T>& ReMasterPtr<T>::operator=(ReMasterPtr&& other) noexcept
	{
		m_objPtr = other.m_objPtr;
		m_referencingObjects = other.m_referencingObjects;
		other.m_objPtr = nullptr;
		other.m_referencingObjects.clear();
		return *this;
	}

	template<class T>
	ReMasterPtr<T>::ReMasterPtr(ReMasterPtr&& other) noexcept : m_objPtr(other.m_objPtr), m_referencingObjects(other.m_referencingObjects)
	{
		other.m_objPtr = nullptr;
		other.m_referencingObjects.clear();
	}

	template <class T>
	ReMasterPtr<T>::~ReMasterPtr()
	{
		if (m_objPtr == nullptr) return;
		for (RePtr<T>* element : m_referencingObjects)
		{
			element->Invalidate();
		}
		
		delete m_objPtr;
	}
}
