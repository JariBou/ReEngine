#pragma once

#include <RealEngine/Core/Export.h>

namespace Re
{
	class ReObject;
}

namespace Re
{
	class RE_CORE_API RePhysicsEngine
	{
		public:
			RePhysicsEngine() = default;
			RePhysicsEngine(const RePhysicsEngine&) = delete;
			RePhysicsEngine(RePhysicsEngine&&) = delete;
			~RePhysicsEngine() = default;

			void ProcessObjectCollisions(ReObject* object);

			RePhysicsEngine& operator=(const RePhysicsEngine&) = delete;
			RePhysicsEngine& operator=(RePhysicsEngine&&) = delete;

		private:
	};
}


