#pragma once

#include <RealEngine/Core/Export.h>

namespace Re
{
	template<class T>
	class ReMasterPtr;

	class ReMasterPtrBase;


	class RePtrBase {
	public:
		virtual void Invalidate() = 0;

		//virtual void PassNewMaster(ReMasterPtrBase* master) = 0;
	};

	template<class T>
	class RePtr : public RePtrBase
	{
		public:
			RePtr() = delete;
			RePtr(const RePtr& other);
			RePtr(const ReMasterPtr<T>& ptrHandler);
			RePtr(RePtr&&) = delete;
			~RePtr();

			template<std::derived_from<T> U>
			RePtr(const RePtr<U>& other);

			template<std::derived_from<T> U>
			RePtr(RePtr<U>&& other);

			T* Get();
			virtual void Invalidate() override;

			RePtr<T>& operator=(const RePtr& other);

			RePtr<T>& operator=(RePtr&& other);

			T* operator-> ()
			{
				return m_objPtr;
			}

		private:
			T* m_objPtr;
			const ReMasterPtr<T>* m_masterPtr;
	};
}

#include <RealEngine/Core/RePtr.inl>
