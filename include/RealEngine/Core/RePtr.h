#pragma once

#include <RealEngine/Core/Export.h>
#include <RealEngine/Core/ReHandledObject.h>

namespace Re
{
	template<typename T>
	class RePtr
	{
		friend ReHandledObject<T>;
		
		public:
		
#pragma region Constructors
			RePtr();
			explicit RePtr(T* object);

			template<typename U>
			explicit RePtr(const RePtr<U>& other);
		
			template<typename U>
			explicit RePtr(RePtr<U>&& other);
		
			RePtr(const RePtr& other) = default;
			RePtr(RePtr&& other) noexcept;
			~RePtr();
#pragma endregion

			T* Get() const;
		
			template<typename U>
			U* GetAs() const;
		
			bool IsValid() const;

			void Reset(T* object);
			void Reset(const RePtr& other);
			void Reset(RePtr&& other);
		
#pragma region Operators
			T* operator->() const;

			template<typename U>
			U* operator->() const;
		
			template<typename U>
			operator U*() const;
		
			explicit operator bool() const; // don't really understand the explicit thing but Rider says so... and Rider is usually right while I'm not
		
			RePtr& operator=(const RePtr&) = delete;
			RePtr& operator=(RePtr&&) = delete;
#pragma endregion
		
		private:
			std::shared_ptr<const ReHandleData> m_data;
	};

}

#include <RealEngine/Core/RePtr.inl>
