#pragma once
#include "IWorldObject.h"


namespace Re
{
	template<Derived<IWorldObject> T, typename ...Args>
	RePtr<T> World::InstantiateObject(Args&&... objectParameters)
	{
		T* newObject = new T(m_engine, std::forward<Args>(objectParameters)...);
		AddObjectToWorld(newObject);
		return RePtr<T>(newObject);
	}
	
	IWorldObjectTemplate
	void World::AddObjectToWorld(T* object)
	{
		m_objectsMap[object] = std::vector<ReComponent*>();

		object->OnPreComponentRegister();
		object->RegisterComponents(m_objectsMap[object]);
		object->OnObjectCreated();
	}
}
