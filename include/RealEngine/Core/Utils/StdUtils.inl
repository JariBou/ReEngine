#pragma once

namespace Re
{
	template <typename T>
	void ArrayUtils::RemoveElement(std::vector<T>& vector, T element)
	{
		vector.erase(std::find(vector.begin(), vector.end(), element));
	}

	template<typename T, typename U>
	void MapUtils::RemoveElementByKey(std::map<T, U>& map, T element)
	{
		auto it = map.find(element);
		map.erase(it);
	}
}
