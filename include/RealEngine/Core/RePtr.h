#pragma once

#include <RealEngine/Core/Export.h>

namespace Re
{
	template<class T>
	class ReMasterPtr;


	class RePtrBase {
	public:
		virtual void Invalidate() = 0;
	};

	template<class T>
	class RePtr : public RePtrBase
	{
		public:
			RePtr() = delete;
			RePtr(const RePtr& other) = delete;
			RePtr(const ReMasterPtr<T>& ptrHandler);
			RePtr(RePtr&&) = delete;
			~RePtr();

			template<std::derived_from<T> U>
			RePtr(const RePtr<U>& other);

			template<std::derived_from<T> U>
			RePtr(RePtr<U>&& other);

			T* Get();
			virtual void Invalidate() override;

			RePtr& operator=(const RePtr&) = delete;
			RePtr& operator=(RePtr&&) = delete;

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
