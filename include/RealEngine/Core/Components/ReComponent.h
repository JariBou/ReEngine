#pragma once

#include <RealEngine/Core/Export.h>

#include <RealEngine/Core/IWorldObject.h>
#include <RealEngine/Core/TagContainer.h>
#include <RealEngine/Core/ObjectHandling/ReHandledObject.h>

namespace Re
{
	class Renderer;
	class ReObject;
	class World;
	
	class RE_CORE_API ReComponent : public ReHandledObject<ReComponent>, public IWorldObject, public TagContainer
	{
#pragma region Constructors
		public:
			ReComponent(ReObject* owner, int priority);
			ReComponent(const ReComponent&) = delete;
			ReComponent(ReComponent&&) = delete;
			~ReComponent() override = default;
#pragma endregion

#pragma region Construction Methods
		public:
			template<DerivedFrom<ReComponent> T, typename... Args>
			static T* Create(Args&&... constructionParams);

			ReComponent* SetPriority(int priority);
		
#pragma endregion

#pragma region IWorldObject Methods
		public:
			World* GetWorld() const override;
			ReEngine* GetEngine() const override;

			void Destroy() override;
			void OnObjectDestroyed() override;
		
#pragma endregion

#pragma region Component Methods
		public:
			RePtr<ReObject> GetOwner() const;

			ReObjectTemplate
			T* GetOwnerAs() { return static_cast<T*>(m_owner); }

			int GetPriority() const;

			bool ShouldTick() const;
			void SetShouldTick(bool state);
		
			virtual void TickComponent();

#pragma endregion

#pragma region Operators
		public:
			ReComponent& operator=(const ReComponent&) = delete;
			ReComponent& operator=(ReComponent&&) = delete;
			
#pragma endregion
		
		protected:
			ReObject* m_owner;
			int m_priority = false;
			bool m_shouldTick = false;
};
	
	template <DerivedFrom<ReComponent> T, typename ... Args>
	T* ReComponent::Create(Args&&... constructionParams)
	{
		T* newComp = new T(std::forward<Args>(constructionParams)...);
		newComp->OnObjectCreated();
		return newComp;
	}
}


