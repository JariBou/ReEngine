#include <iostream>
#include <ostream>

#pragma once
#include "RePtr.h"
#include <iostream>

namespace Re
{
	//template<class T>
	//inline RePtr<T>::RePtr(const RePtr& other)
	//{
	//	m_objPtr = other.m_objPtr;
	//	
	//}

	template <class T>
	RePtr<T>::~RePtr()
	{
		std::cout << "Destroying RePtr" << std::endl;
		if (m_masterPtr == nullptr) return;
		m_masterPtr->Unregister(this);
	}

	template<class T>
	template<std::derived_from<T> U>
	inline Re::RePtr<T>::RePtr(const RePtr<U>& other)
	{
		m_objPtr = other->m_objPtr;
		m_masterPtr = other->ptrMaster;
		m_masterPtr->Register(this);
	}

	template<class T>
	template<std::derived_from<T> U>
	inline RePtr<T>::RePtr(RePtr<U>&& other)
	{
		m_objPtr = other->m_objPtr;
		m_masterPtr = other->ptrMaster;
		m_masterPtr->Register(this);
	}

	template<class T>
	inline RePtr<T>::RePtr(const ReMasterPtr<T>& ptrMaster)
	{
		m_masterPtr = &ptrMaster;
		m_objPtr = ptrMaster.m_objPtr;
		m_masterPtr->Register(this);
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
		m_masterPtr = nullptr;
	}
}
