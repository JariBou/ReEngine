#pragma once

namespace Re
{
	template <typename T>
	List<T>::List()
	{
		data = std::vector<T>();
	}

	template <typename T>
	void List<T>::Add(T&& item)
	{
		if (data.size() == data.capacity()) data.reserve(data.capacity() * 2);
		data.push_back(std::move(item));
	}

	template <typename T>
	void List<T>::Remove(T& item)
	{
		auto it = std::find(data.begin(), data.end(), item);
		data.erase(it);
	}
}
