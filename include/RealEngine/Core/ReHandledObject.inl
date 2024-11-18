#pragma once

#include <cassert>

namespace Re
{
	template <typename T>
	ReHandledObject<T>::~ReHandledObject()
	{
		UnregisterAllHandles();
	}

	template <typename T>
	std::shared_ptr<const ReHandleData> ReHandledObject<T>::GetData()
	{
		if (!m_handleData) InitHandleData();

		return std::shared_ptr<const ReHandleData>(m_handleData);
	}

	template <typename T>
	void ReHandledObject<T>::UnregisterAllHandles() noexcept
	{
		if (m_handleData == nullptr) return;

		m_handleData->object = nullptr;
		m_handleData.reset();
	}

	template<typename T>
	void ReHandledObject<T>::InitHandleData()
	{
		assert(!m_handleData); // Ok this looks cool

		m_handleData = std::make_shared<ReHandleData>();
		m_handleData->object = static_cast<T*>(this);
	}
}
