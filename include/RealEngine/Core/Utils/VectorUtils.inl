#pragma once

namespace Re
{
	template <typename T>
	void VectorUtils::RemoveElement(std::vector<T>& vector, T element)
	{
		vector.erase(std::find(vector.begin(), vector.end(), element));
	}
}
