#pragma once

#include <RealEngine/Core/Export.h>
#include <RealEngine/Core/RePtrBases.h>

namespace Re
{
	template<class T>
	class ReMasterPtr;

	template<class T>
	class RePtr : public RePtrBase
	{
		public:
			RePtr() = delete;
		
			RePtr(RePtr& other);
			RePtr(const RePtr& other);
			RePtr(const ReMasterPtr<T>& ptrMaster);
			RePtr(const ReMasterPtr<T>* ptrMaster);

			RePtr(RePtr&& other) noexcept;
			~RePtr();

			template<std::derived_from<T> U>
			RePtr(const RePtr<U>& other);

			template<std::derived_from<T> U>
			RePtr(RePtr<U>&& other);

			T* Get();
		
			bool IsValid();
		
			void Invalidate() override;

			RePtr& operator=(const RePtr& other);

			RePtr& operator=(RePtr&& other) noexcept;

			T* operator-> ()
			{
				return m_objPtr;
			}

			void PassNewMaster(ReMasterPtrBase* master) override;

		private:
			T* m_objPtr;
			const ReMasterPtrBase* m_masterPtr;

			template<typename U>
			friend class RePtr;
	};
}

#include <RealEngine/Core/RePtr.inl>
