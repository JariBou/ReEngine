#pragma once

#include "RePtr.h"
#include "ReMasterPtr.h"

namespace Re
{
	//template<class T>
	//inline RePtr<T>::RePtr(const RePtr& other)
	//{
	//	m_objPtr = other.m_objPtr;
	//	
	//}

	template<class T>
	inline RePtr<T>::RePtr(const ReMasterPtr<T>& ptrHandler)
	{
		m_objPtr = ptrHandler.m_objPtr;
		ptrHandler.m_referencingObjects.push_back(this);
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
