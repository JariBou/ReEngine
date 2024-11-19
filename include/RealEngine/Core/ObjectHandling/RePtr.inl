#include "RePtr.h"
#pragma once

namespace Re
{
	template <typename T>
	RePtr<T>::RePtr() : m_data(ReHandleData::GetEmptyObject())
	{
	}

	template <typename T>
	RePtr<T>::RePtr(T* object)
	{
		Reset(object);
	}

	template <typename T>
	template <BaseOf<T> U>
	RePtr<T>::RePtr(const RePtr<U>& other)
	{
		//static_assert(std::derived_from<T, U>);
		if (other.template GetAs<T>() != nullptr) {
			m_data = other.m_data;
		} else
		{
			m_data = ReHandleData::GetEmptyObject();
		}
	}
	
	template <typename T>
	template <BaseOf<T> U>
	RePtr<T>::RePtr(RePtr<U>&& other)
	{
		//static_assert(std::derived_from<T, U>);
		//static_assert(other.template GetAs<T>() != nullptr, "RePtr<T>::RePtr<T>: Invalid RePtr");
		if (other.template GetAs<T>() != nullptr) {
			m_data = std::move(other.m_data);
			other.m_data = ReHandleData::GetEmptyObject();
		} else
		{
			m_data = ReHandleData::GetEmptyObject();
		}
		other.m_data = ReHandleData::GetEmptyObject();
	}

	template <typename T>
	template <DerivedFrom<T> U>
	RePtr<T>::RePtr(const RePtr<U>& other) : m_data(other.m_data)
	{
	}

	template <typename T>
	template <DerivedFrom<T> U>
	RePtr<T>::RePtr(RePtr<U>&& other) :
	m_data(std::move(other.m_data))
	{
		other.m_data = ReHandleData::GetEmptyObject();
	}

	template <typename T>
	RePtr<T>::~RePtr()
	{
		Reset(nullptr);
	}

	// template<typename T>
	// template<typename U>
	// RePtr<T>::RePtr(const RePtr<U>& other) :
	// m_data(other.m_data)
	// {
	// 	static_assert(std::is_base_of_v<T, U>, "Can only implicitly convert from a derived to a base");
	// }
	//
	// template<typename T>
	// template<typename U>
	// RePtr<T>::RePtr(RePtr<U>&& other) :
	// m_data(std::move(other.m_data))
	// {
	// 	other.m_handleData = ReHandleData::GetEmptyObject();
	//
	// 	static_assert(std::is_base_of_v<T, U>, "Can only implicitly convert from a derived to a base");
	// }

	template <typename T>
	RePtr<T>::RePtr(RePtr&& other) noexcept
	{
		m_data = std::move(other.m_data);
		other.m_data = ReHandleData::GetEmptyObject();
	}
	
	template <typename T>
	T* RePtr<T>::Get() const
	{
		if (m_data == nullptr) return nullptr;
		return static_cast<T*>(m_data->object);
	}

	template <typename T>
	template <DerivedFrom<T> U>
	U* RePtr<T>::GetAs() const
	{
		if (m_data == nullptr) return nullptr;
		return static_cast<U*>(m_data->object);
	}

	template<typename T>
	template<DerivedFrom<T> U>
	U* RePtr<T>::GetAsDynamic() const
	{
		if (m_data == nullptr) return nullptr;
		return dynamic_cast<U*>(m_data->object);
	}

	template <typename T>
	bool RePtr<T>::IsValid() const
	{
		return m_data->object != nullptr;
	}

	template <typename T>
	void RePtr<T>::Reset(T* object)
	{
		if (object == nullptr)
		{
			m_data = ReHandleData::GetEmptyObject();
		} else
		{
			m_data = object->GetData();
		}
		//m_data = object == nullptr ? ReHandleData::GetEmptyObject() : object->GetData();
	}

	template<typename T>
	void RePtr<T>::Reset(const RePtr& other)
	{
		m_data = other.m_data;
	}

	template<typename T>
	void RePtr<T>::Reset(RePtr&& other)
	{
		m_data = std::move(other.m_data);
		other.m_data = ReHandleData::GetEmptyObject();
	}

	template<typename T>
	T* RePtr<T>::operator->() const
	{
		return Get();
	}

	template <typename T>
	template <DerivedFrom<T> U>
	U* RePtr<T>::operator->() const
	{
		return GetAs<U>();
	}
	
	template <typename T>
	template <DerivedFrom<T> U>
	RePtr<T>::operator U*() const
	{
		return GetAs<U>();
	}

	template <typename T>
	template <DerivedFrom<T> U>
	RePtr<T>::operator RePtr<U>*() const
	{
		return RePtr<U>(GetAs<U>());
	}

	template <typename T>
	template <BaseOf<T> U>
	RePtr<T>::operator RePtr<U>*() const
	{
		return RePtr<U>(static_cast<U*>(Get()));
	}

	// template <typename T>
	// template <typename U>
	// RePtr<T>::operator U*() const
	// {
	// 	return GetAs<U>();
	// }

	template<typename T>
	Re::RePtr<T>::operator bool() const
	{
		return IsValid();
	}

	// template <typename T>
	// template <BaseOf<T> U>
	// RePtr<U>& RePtr<T>::operator=(const RePtr<U>&)
	// {
	// 	return RePtr<U>(static_cast<U*>(Get()));
	// }
}
