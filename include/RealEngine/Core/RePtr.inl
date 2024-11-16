#pragma once
#include <iostream>
#include <ostream>
#include "RePtr.h"

namespace Re
{
	template <class T>
	RePtr<T>::~RePtr()
	{
		std::cout << "Destroying RePtr" << "\n";
		if (m_masterPtr == nullptr) return;
		m_masterPtr->Unregister(this);
	}

	template<class T>
	template<std::derived_from<T> U>
	Re::RePtr<T>::RePtr(const RePtr<U>& other)
	{
		m_objPtr = other.m_objPtr;
		m_masterPtr = other.m_masterPtr;
		if (m_masterPtr == nullptr) return;
		m_masterPtr->Register(this);
	}

	template<class T>
	template<std::derived_from<T> U>
	RePtr<T>::RePtr(RePtr<U>&& other)
	{
		m_objPtr = other.m_objPtr;
		m_masterPtr = other.m_masterPtr;
		if (m_masterPtr == nullptr) return;
		m_masterPtr->Register(this);
	}

	template <class T>
	RePtr<T>::RePtr(RePtr& other)
	{
		m_objPtr = other.m_objPtr;
		m_masterPtr = other.m_masterPtr;
		if (m_masterPtr == nullptr) return;
		m_masterPtr->Register(this);
	}

	template <class T>
	RePtr<T>::RePtr(const RePtr& other)
	{
		m_objPtr = other.m_objPtr;
		m_masterPtr = other.m_masterPtr;
		if (m_masterPtr == nullptr) return;
		m_masterPtr->Register(this);
	}

	template<class T>
	RePtr<T>::RePtr(const ReMasterPtr<T>& ptrMaster)
	{
		m_masterPtr = &ptrMaster;
		m_objPtr = ptrMaster.m_objPtr;
		if (m_masterPtr == nullptr) return;
		m_masterPtr->Register(this);
	}

	template <class T>
	RePtr<T>::RePtr(const ReMasterPtr<T>* ptrMaster)
	{
		m_masterPtr = ptrMaster;
		m_objPtr = ptrMaster->m_objPtr;
		if (m_masterPtr == nullptr) return;
		m_masterPtr->Register(this);
	}

	template <class T>
	RePtr<T>::RePtr(RePtr&& other) noexcept
	{
		m_objPtr = other.m_objPtr;
		m_masterPtr = other.m_masterPtr;
		if (m_masterPtr == nullptr) return;
		m_masterPtr->Register(this);
	}

	template<class T>
	T* RePtr<T>::Get()
	{
		return m_objPtr;
	}

	template <class T>
	bool RePtr<T>::IsValid()
	{
		return m_objPtr != nullptr;
	}

	template<class T>
	void RePtr<T>::Invalidate()
	{
		m_objPtr = nullptr;
		m_masterPtr = nullptr;
		std::cout << "Invalidating RePtr" << std::endl;
	}

	template<class T>
	RePtr<T>& RePtr<T>::operator=(const RePtr& other)
	{
		if (this == &other) return *this;
		
		m_objPtr = other.m_objPtr;
		m_masterPtr = other.m_masterPtr;
		if (m_masterPtr != nullptr) m_masterPtr->Register(this);
		return *this;
	}

	template<class T>
	RePtr<T>& RePtr<T>::operator=(RePtr&& other) noexcept
	{
		m_objPtr = other.m_objPtr;
		m_masterPtr = other.m_masterPtr;
		if (m_masterPtr != nullptr) m_masterPtr->Register(this);
		return *this;
	}

	template<class T>
	void Re::RePtr<T>::PassNewMaster(ReMasterPtrBase* master)
	{
		m_masterPtr = master;
	}
}
