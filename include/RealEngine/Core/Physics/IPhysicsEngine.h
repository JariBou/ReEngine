#pragma once

#include <RealEngine/Core/Export.h>

namespace Re
{
	class RE_CORE_API IPhysicsEngine
	{
		public:
			IPhysicsEngine() = default;
			IPhysicsEngine(const IPhysicsEngine&) = delete;
			IPhysicsEngine(IPhysicsEngine&&) = delete;
			~IPhysicsEngine() = default;

			IPhysicsEngine& operator=(const IPhysicsEngine&) = delete;
			IPhysicsEngine& operator=(IPhysicsEngine&&) = delete;

		private:
	};
}


