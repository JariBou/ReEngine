#pragma once

#include <vector>
#include <RealEngine/Core/Export.h>
#include <RealEngine/Core/ObjectHandling/ReHandledObject.h>


namespace Re
{
	class ReComponent;
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
		
			void DestroyObject();
		
			virtual void RegisterComponents(std::vector<ReComponent*>& componentList);
		
			World* GetWorld() const;
		
			ReObject& operator=(const ReObject&) = delete;
			ReObject& operator=(ReObject&&) = delete;

		protected:
			ReEngine* m_engine;
	};
}


