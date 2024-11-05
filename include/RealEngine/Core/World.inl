#pragma once

namespace Re
{
	template<Derived<ReObject> T>
	inline T* World::InstantiateObject()
	{
		T* newObject = new T(nullptr);
		ReMasterPtr<T> val = ReMasterPtr<T>(newObject);
		//this->m_objects.push_back(newObject);
		this->m_objectsV2.push_back(val);
		return newObject;
	}
}
