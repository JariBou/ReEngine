#include "RePtr.h"
#pragma once

namespace Re
{
	//template<class T>
	//inline RePtr<T>::RePtr(const RePtr& other)
	//{
	//	m_objPtr = other.m_objPtr;
	//	
	//}

	template<class T>
	template<std::derived_from<T> U>
	inline Re::RePtr<T>::RePtr(RePtr<U>& other)
	{
		m_objPtr = other->m_objPtr;
	}

	template<class T>
	template<std::derived_from<T> U>
	inline RePtr<T>::RePtr(RePtr<U>&& other)
	{
		m_objPtr = other->m_objPtr;
	}

	template<class T>
	inline RePtr<T>::RePtr(const ReMasterPtr<T>& ptrMaster)
	{
		m_objPtr = ptrMaster.m_objPtr;
		ptrMaster.m_referencingObjects.push_back(this);
	}

	template<class T>
	inline T* RePtr<T>::Get()
	{
		return m_objPtr;
	}

	template<class T>
	inline void RePtr<T>::Invalidate()
	{
		m_objPtr = nullptr;
	}
}
