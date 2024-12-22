#pragma once

#include <RealEngine/Core/Export.h>

namespace Re
{
	class World;

	class RE_CORE_API ReLevelBase
	{
		

		public:
			ReLevelBase() = default;
			ReLevelBase(const ReLevelBase&) = delete;
			ReLevelBase(ReLevelBase&&) = delete;
			virtual ~ReLevelBase() = default;

			void LoadLevelInWorld(World* World);

			virtual void PreLevelLoad(World* World) = 0;
			virtual void LevelLoad(World* World) = 0;
			virtual void PostLevelLoad(World* World) = 0;

			ReLevelBase& operator=(const ReLevelBase&) = delete;
			ReLevelBase& operator=(ReLevelBase&&) = delete;
		
		private:
			
	};

	
}

#include <RealEngine/Core/ReLevelBase.inl>
