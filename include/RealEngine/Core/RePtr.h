#pragma once

#include <RealEngine/Core/Export.h>

namespace Re
{
	class RE_CORE_API RePtr
	{
		public:
			RePtr() = default;
			RePtr(const RePtr&) = delete;
			RePtr(RePtr&&) = delete;
			~RePtr() = default;

			RePtr& operator=(const RePtr&) = delete;
			RePtr& operator=(RePtr&&) = delete;

		private:
	};
}

#include <RealEngine/Core/RePtr.inl>
