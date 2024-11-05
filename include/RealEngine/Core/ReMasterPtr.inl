#pragma once

namespace Re
{
	template<class T>
	inline T* Re::ReMasterPtr<T>::Get()
	{
		return m_objPtr;
	}

	template <class T>
	ReMasterPtr<T>& ReMasterPtr<T>::operator=(ReMasterPtr&& other)
	{
		m_objPtr = other.m_objPtr;
		m_referencingObjects = other.m_referencingObjects;
		return *this;
	}

	template<class T>
	inline Re::ReMasterPtr<T>::ReMasterPtr(ReMasterPtr&& other) : m_objPtr(other.m_objPtr), m_referencingObjects(other.m_referencingObjects)
	{
		
	}

	template <class T>
	ReMasterPtr<T>::~ReMasterPtr()
	{
		for (RePtr<T>* element : m_referencingObjects)
		{
			element->Invalidate();
		}
		
		delete m_objPtr;
	}
}
