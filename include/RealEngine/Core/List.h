#pragma once

#include <RealEngine/Core/Export.h>
#include <vector>

namespace Re
{
	template <typename T>
	class List
	{
		public:
			List();
			List(const List&) = delete;
			List(List&&) = delete;
			~List() = default;

			List& operator=(const List&) = delete;
			List& operator=(List&&) = delete;

			std::vector<T>& GetData()
			{
				return data;
			}

			void Add(T& item);
		
			void Add(T&& item);
		
			void Remove(T& item);

		private:
			std::vector<T> data;
	};
}

#include <RealEngine/Core/List.inl>
