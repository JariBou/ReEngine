#pragma once


namespace Re
{
// 	#pragma region Components
//
// 	
//
// 	template <Derived<ReComponent> T>
// 	void World::RegisterComponent(RePtr<T>* component, RePtr<ReObject>* owner)
// 	{
// 		if (owner == nullptr) return;
//
// 		
// 	}
//
// 	template <Derived<ReComponent> T>
// 	RePtr<T> World::CreateComponent(ReObject* owner)
// 	{
// 		ReMasterPtr<T> pComp = ReMasterPtr<T>(owner);
// 		RePtr<T> rePtrComp(pComp);
//
// 		RegisterComponent(rePtrComp, GetRePtrTo(owner));
//
// 		// m_componentMap[rePtr] = pComp;
// 		
// 		return rePtrComp;
// 	}
//     
// 	template <Derived<ReComponent> T>
// 	size_t World::GetObjectIndex(RePtr<T>* component)
// 	{
// 		auto isSame = [&component](ReMasterPtr<ReComponent>* pComp) {return pComp == component;};
// 		auto it = std::find_if(m_objectsV2.begin(), m_objectsV2.end(), isSame);
// 		return it - m_objectsV2.begin();
// 	}
// #pragma endregion

	// template<Derived<ReObject> T, typename... Args>
	// RePtr<T> World::InstantiateObject(Args&&... ObjectParameters)
	// {
	// 	//T* newObject = new T(nullptr);
	// 	//TODO: optimize this bish
	// 	ReMasterPtr<T> val = ReMasterPtr<T>(m_engine, ObjectParameters...);
	// 	RePtr<T> rePtr(val);
	// 	// ReMasterPtr<ReObject>* val = new ReMasterPtr<T>(newObject);
	// 	//this->m_objects.push_back(newObject);
	//
	// 	AddObjectToWorld(val);
	// 	// AddObjectToWorld(std::move(val));
	// 	// this->m_objectsV2.push_back(std::move(val));
	//
	// 	// Re::ReMasterPtr<T>* reMasterPtr = &this->m_objectsV2.at(this->m_objectsV2.size() - 1);
	// 	// Re::ReMasterPtr<ReObject>* reMasterPtr = &this->m_objectsV2.back();
	// 	
	// 	// Ici le ReMasterPtr passé en paramètre de RePtr est détruit après... wtf
	// 	// return RePtr<T>(static_cast<ReMasterPtr<T>>(this->m_objectsV2.back()));
	// 	// return RePtr<T>(static_cast<ReMasterPtr<T>*>(reMasterPtr));
	// 	return rePtr;
	// }
	//
	// template<Derived<ReObject> T>
	// // void World::AddObjectToWorld(ReMasterPtr<T>&& item)
	// // void World::AddObjectToWorld(ReMasterPtr<T>* item)
	// void World::AddObjectToWorld(ReMasterPtr<T>& item)
	// {
	// 	if (m_objectsV2.size() == m_objectsV2.capacity()) m_objectsV2.reserve(m_objectsV2.capacity() * 2);
	//
	// 	if (RendererComponent* component = dynamic_cast<RendererComponent*>(item.Get()); component != nullptr)
	// 	{
	// 		if (m_renderedObjects.size() == m_renderedObjects.capacity()) m_renderedObjects.reserve(m_renderedObjects.capacity() * 2);
	// 		m_renderedObjects.push_back(component);
	// 	}
	// 	
	// 	// m_objectsV2.push_back(item);
	// 	m_objectsV2.push_back(std::move(item));
	// }

	template<typename T, typename ...Args>
	RePtr<T> World::InstantiateObject(Args&&... objectParameters)
	{
		T* newObject = new T(m_engine, std::forward<Args>(objectParameters)...);
		AddObjectToWorld(newObject);
		return RePtr<T>(newObject);
	}
	
	template<typename T>
	void World::AddObjectToWorld(T* object)
	{
		//TODO push back creates new allocation wtf??
		if (m_objects.size() == m_objects.capacity()) m_objects.reserve(m_objects.capacity() * 2);
		m_objects.push_back(object);
		m_objectsMap[object] = std::vector<ReComponent*>();

		object->RegisterComponents(m_objectsMap[object]);
	}
}
