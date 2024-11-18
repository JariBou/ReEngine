#pragma once

#include <RealEngine/Core/Export.h>
#include <RealEngine/Core/ReHandledObject.h>


namespace Re
{
	class ReEngine;
	class World;
	class RePtrData;

	class RE_CORE_API ReObject : public ReHandledObject<ReObject>
	{
		public:
			ReObject(ReEngine* engine);

			ReObject(const ReObject&) = delete;
			ReObject(ReObject&&) = delete;
			~ReObject() override;

			virtual void Tick();

			void DestroyObject();

			World* GetWorld() const;
			bool ShouldTick() const;
			void SetShouldTick(bool state);
		
			ReObject& operator=(const ReObject&) = delete;
			ReObject& operator=(ReObject&&) = delete;

		private:
			bool m_shouldTick = false;
			ReEngine* m_engine;
	};
}


