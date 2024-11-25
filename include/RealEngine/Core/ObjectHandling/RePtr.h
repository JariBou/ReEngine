#pragma once

#include <RealEngine/Core/Export.h>
#include <RealEngine/Core/ObjectHandling/ReHandledObject.h>

namespace Re
{	
	template<typename T>
	class RePtr
	{
		friend ReHandledObject<T>;
		template<typename U>
		friend class RePtr;
		
		public:
		
#pragma region Constructors
			RePtr();
			
			explicit RePtr(T* object);

			template<BaseOf<T> U>
			RePtr(const RePtr<U>& other);
			
			template<BaseOf<T> U>
			RePtr(RePtr<U>&& other);

			template<DerivedFrom<T> U>
			RePtr(const RePtr<U>& other);
			
			template<DerivedFrom<T> U>
			RePtr(RePtr<U>&& other);
		
			RePtr(const RePtr& other) = default;
			RePtr(RePtr&& other) noexcept;
			~RePtr();
#pragma endregion

			T* Get() const;
		
			template<DerivedFrom<T> U>
			U* GetAs() const;

			// DONT USE DYNAMIC_CAST BUT JUST IN CAS IT'S HERE
			template<DerivedFrom<T> U>
			U* GetAsDynamic() const;
		
			bool IsValid() const;

			void Reset(T* object);
			void Reset(const RePtr& other);
			void Reset(RePtr&& other);
		
#pragma region Operators
			T* operator->() const;

			// Not sure about these =======================
			template<DerivedFrom<T> U>
			U* operator->() const;
		
			template<DerivedFrom<T> U>
			operator U*() const;
		
			template<DerivedFrom<T> U>
			operator RePtr<U>*() const;

			template<BaseOf<T> U>
			operator RePtr<U>*() const;
			// =============================================
		
			explicit operator bool() const; // don't really understand the explicit thing but Rider says so... and Rider is usually right while I'm not
		
			RePtr& operator=(const RePtr& other);
			RePtr& operator=(RePtr&& other) noexcept;

#pragma endregion
		
		private:
			std::shared_ptr<const ReHandleData> m_data;
	};

}

#include <RealEngine/Core/ObjectHandling/RePtr.inl>
