#pragma once

#include "RePtr.h"
#include "World.h"

namespace Re
{
	template<Derived<ReObject> T, typename... Args>
	RePtr<T> World::InstantiateObject(Args&&... ObjectParameters)
	{
		//T* newObject = new T(nullptr);
		//TODO: optimize this bish
		ReMasterPtr<T> val = ReMasterPtr<T>(m_engine, ObjectParameters...);
		RePtr<T> rePtr(val);
		// ReMasterPtr<ReObject>* val = new ReMasterPtr<T>(newObject);
		//this->m_objects.push_back(newObject);

		AddObjectToWorld(val);
		// AddObjectToWorld(std::move(val));
		// this->m_objectsV2.push_back(std::move(val));

		// Re::ReMasterPtr<T>* reMasterPtr = &this->m_objectsV2.at(this->m_objectsV2.size() - 1);
		// Re::ReMasterPtr<ReObject>* reMasterPtr = &this->m_objectsV2.back();
		
		// Ici le ReMasterPtr passé en paramètre de RePtr est détruit après... wtf
		// return RePtr<T>(static_cast<ReMasterPtr<T>>(this->m_objectsV2.back()));
		// return RePtr<T>(static_cast<ReMasterPtr<T>*>(reMasterPtr));
		return rePtr;
	}

	template<Derived<ReObject> T>
	// void World::AddObjectToWorld(ReMasterPtr<T>&& item)
	// void World::AddObjectToWorld(ReMasterPtr<T>* item)
	void World::AddObjectToWorld(ReMasterPtr<T>& item)
	{
		if (m_objectsV2.size() == m_objectsV2.capacity()) m_objectsV2.reserve(m_objectsV2.capacity() * 2);
		// m_objectsV2.push_back(item);
		m_objectsV2.push_back(std::move(item));
	}
}
