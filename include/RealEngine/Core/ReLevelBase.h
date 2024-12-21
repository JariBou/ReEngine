#pragma once

#include <RealEngine/Core/Export.h>
#include <SerializationLib/SerializableObject.h>

namespace Re
{
	class World;

	class RE_CORE_API ReLevelBase : public Serialization::SerializableObject
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
		
		protected:
			void OnSerialize(Serialization::Serializer* serializer) const override = 0;
			void OnDeserialize(Serialization::Deserializer* deserializer) override = 0;
		
		private:
			
	};

	
}

#include <RealEngine/Core/ReLevelBase.inl>
