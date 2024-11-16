#pragma once

#include <RealEngine/Core/Export.h>

namespace Re
{
	class ReEngine;
	class World;

	class RE_CORE_API ReObject
	{
		public:
			ReObject(ReEngine* engine);

			ReObject(const ReObject&) = delete;
			ReObject(ReObject&&) = delete;
			virtual ~ReObject();

			virtual void Tick();

			World* GetWorld();
			bool ShouldTick();
			void SetShouldTick(bool state);

			ReObject& operator=(const ReObject&) = delete;
			ReObject& operator=(ReObject&&) = delete;

		private:
			bool m_shouldTick = false;
			ReEngine* m_engine;
	};
}


