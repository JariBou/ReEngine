#pragma once

#include <RealEngine/Core/Export.h>

namespace Re
{
	class ReEngine;
	class World;

	//TODO: see if IWorldObject can be used more often
	class RE_CORE_API IWorldObject
	{
		public:
			IWorldObject() = default;
			IWorldObject(const IWorldObject&) = delete;
			IWorldObject(IWorldObject&&) = delete;
			virtual ~IWorldObject() = default;

			virtual void OnPreComponentRegister();
			virtual void OnObjectCreated();
			virtual void Destroy() = 0;
			virtual void OnObjectDestroyed() = 0;

			virtual World* GetWorld() const = 0;
			virtual ReEngine* GetEngine() const = 0;
		
			virtual bool IsPendingDestroy() const;

			IWorldObject& operator=(const IWorldObject&) = delete;
			IWorldObject& operator=(IWorldObject&&) = delete;

		protected:
			bool m_isPendingDestroy = false;
	};
}


