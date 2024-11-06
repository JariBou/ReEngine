#include "ReMasterPtr.h"
#pragma once

namespace Re
{
	template<class T>
	T* ReMasterPtr<T>::Get()
	{
		return m_objPtr;
	}

	template <class T>
	void ReMasterPtr<T>::Register(RePtrBase* item) const
	{
		m_referencingObjects.push_back(item);
	}

	template <class T>
	void ReMasterPtr<T>::Unregister(RePtrBase* item) const
	{
		auto iterator = std::find(m_referencingObjects.begin(), m_referencingObjects.end(), item);
		if (iterator == m_referencingObjects.end()) return;
		
		m_referencingObjects.erase(iterator);
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

	template <class T>
	ReMasterPtr<T>::ReMasterPtr()
	{
		m_objPtr = new T(nullptr);
	}

	template<class T>
	ReMasterPtr<T>::ReMasterPtr(ReMasterPtr&& other) noexcept : m_objPtr(other.m_objPtr), m_referencingObjects(std::move(other.m_referencingObjects))
	{
		other.m_objPtr = nullptr;
		other.m_referencingObjects.clear();
	}

	template <class T>
	ReMasterPtr<T>::~ReMasterPtr()
	{
		for (RePtrBase* element : m_referencingObjects)
		{
			element->Invalidate();
		}
		delete m_objPtr;
	}

	template<class T>
	template<std::derived_from<T> U>
	inline ReMasterPtr<T>::ReMasterPtr(ReMasterPtr<U>& other) : m_objPtr(other.m_objPtr), m_referencingObjects(other.m_referencingObjects)
	{
		other.m_objPtr = nullptr;
		other.m_referencingObjects.clear();
	}

	template<class T>
	template<std::derived_from<T> U>
	inline ReMasterPtr<T>::ReMasterPtr(ReMasterPtr<U>&& other) : m_objPtr(other.m_objPtr), m_referencingObjects(other.m_referencingObjects)
	{
		other.m_objPtr = nullptr;
		other.m_referencingObjects.clear();
	}
}
