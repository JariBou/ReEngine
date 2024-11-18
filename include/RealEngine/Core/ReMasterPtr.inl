#pragma once

namespace Re
{

	template <typename T>
	template<typename ...Args>
	ReMasterPtr<T>::ReMasterPtr(Args&&... constructorParams)
	{
		T* newObj = new T(constructorParams...);
		Reset(newObj);
	}
	
	template <typename T>
	ReMasterPtr<T>::ReMasterPtr(ReMasterPtr&& other) noexcept : m_data(std::move(other->m_data))
	{
		other->m_data = RePtrData::GetEmptyObject();
	}

	template<typename T>
	ReMasterPtr<T>::~ReMasterPtr()
	{
		delete m_data->object;
		m_data->object = nullptr;
	}

	template<typename T>
	T* ReMasterPtr<T>::GetObject()
	{
		return static_cast<T*>(m_data->object);
	}

	template <typename T>
	void ReMasterPtr<T>::Reset(T* object)
	{
		if (object == nullptr)
		{
			m_data = RePtrData::GetEmptyObject();
		} else
		{
			// TODO
			// m_data = object;
		}
	}

	template <typename T>
	std::shared_ptr<const RePtrData> ReMasterPtr<T>::GetData() const
	{
		return std::shared_ptr<const RePtrData>(m_data);
	}
}
