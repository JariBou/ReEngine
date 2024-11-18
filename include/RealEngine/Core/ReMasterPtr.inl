#pragma once

namespace Re
{
	template<typename T>
	inline Re::ReMasterPtr<T>::~ReMasterPtr()
	{
		
	}

	template<typename T>
	inline T* Re::ReMasterPtr<T>::GetObject()
	{
		return static_cast<T*>(m_data->object);
	}
}
