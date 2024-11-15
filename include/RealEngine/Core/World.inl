#pragma once

#include "RePtr.h"

namespace Re
{
	template<Derived<ReObject> T>
	RePtr<T> World::InstantiateObject()
	{
		//T* newObject = new T(nullptr);
		ReMasterPtr<T> val = ReMasterPtr<T>();
		// ReMasterPtr<ReObject>* val = new ReMasterPtr<T>(newObject);
		//this->m_objects.push_back(newObject);
		this->m_objectsV2.push_back(std::move(val));
		// Ici le ReMasterPtr passé en paramètre de RePtr est détruit après... wtf
		return RePtr<T>(static_cast<ReMasterPtr<T>>(this->m_objectsV2.back()));
	}
}
