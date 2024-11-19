#pragma once

#include <vector>
#include <RealEngine/Core/Export.h>
#include <RealEngine/Core/ObjectHandling/ReHandledObject.h>

#include "IWorldObject.h"


namespace Re
{
	class ReComponent;
	class ReEngine;
	class World;
	class RePtrData;

	class RE_CORE_API ReObject : public ReHandledObject<ReObject>, public IWorldObject
	{
		public:
			ReObject(ReEngine* engine);

			ReObject(const ReObject&) = delete;
			ReObject(ReObject&&) = delete;
			~ReObject() override;
		
#pragma region IWorldObject Methods

			World* GetWorld() const override;
		
			void Destroy() override;
			void OnObjectDestroyed() override;
		
#pragma endregion
		
			virtual void RegisterComponents(std::vector<ReComponent*>& componentList);

			ReObject& operator=(const ReObject&) = delete;
			ReObject& operator=(ReObject&&) = delete;

		protected:
			ReEngine* m_engine;
	};
}


