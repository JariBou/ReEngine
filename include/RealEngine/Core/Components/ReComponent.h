#pragma once

#include <RealEngine/Core/Export.h>

#include "RealEngine/Core/ObjectHandling/ReHandledObject.h"


namespace Re
{
	class ReObject;
	class World;
	
	class RE_CORE_API ReComponent : public ReHandledObject<ReComponent>
	{
		public:
#pragma region Constructors
			ReComponent(ReObject* owner, int priority);
			ReComponent(const ReComponent&) = delete;
			ReComponent(ReComponent&&) = delete;
			virtual ~ReComponent() = default;
#pragma endregion

#pragma region Construction Methods

			template<typename T, typename... Args>
			static T* Create(Args&&... constructionParams);

			ReComponent* SetPriority(int priority);
		
#pragma endregion

#pragma region Component Methods
			RePtr<ReObject> GetOwner() const;

			template<typename T>
			T* GetOwnerAs() { return static_cast<T*>(m_owner); }

			int GetPriority() const;

			World* GetWorld() const;

			bool ShouldTick() const;
			void SetShouldTick(bool state);

			virtual void DestroyComponent();
		
			virtual void TickComponent();
#pragma endregion

#pragma region Operators
			ReComponent& operator=(const ReComponent&) = delete;
			ReComponent& operator=(ReComponent&&) = delete;
#pragma endregion
		
		protected:
			ReObject* m_owner;
			int m_priority = false;
			bool m_shouldTick = false;
};

	template <typename T, typename ... Args>
	T* ReComponent::Create(Args&&... constructionParams)
	{
		T* newComp = new T(std::forward<Args>(constructionParams)...);
		return newComp;
	}
}


