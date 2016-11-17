#ifndef CPPNET_BOX_HPP
#define CPPNET_BOX_HPP

#include "System/NullReferenceException.hpp"

namespace CppNet
{
	// From
	// https://gist.github.com/kiwiyou/d30cff6f5952aa1c2a6db39b4609124d
	// Thank you!

	template<typename T>
	class Box final
	{
	private:
		T* data = nullptr;
		size_t* ref_count = nullptr;

	public:
		Box()
		{
			data = new T{};
			ref_count = new size_t(1);
		}

		Box(std::nullptr_t null)
		{}

		Box(const Box<T>& box)
		{
			if (box == nullptr) return;

			data = box.data;
			ref_count = box.ref_count;
			++(*ref_count);
		}

		Box(Box<T>&& box)
		{
			if (box == nullptr) return;

			data = box.data;
			ref_count = box.ref_count;

			box.data = nullptr;
			box.ref_count = nullptr;
		}

		Box(const T& value)
		{
			data = new T(value);
			ref_count = new size_t(1);
		}

		Box(T&& value)
		{
			data = new T(value);
			ref_count = new size_t(1);
		}

		~Box()
		{
			if (data)
			{
				if (*ref_count == 1)
				{
					delete data;
					delete ref_count;
				}
				else
				{
					data = nullptr;
					--(*ref_count);
				}
			}
		}

	public:
		const T& operator*() const
		{
			if (!data)
				throw NullReferenceException();

			return *data;
		}

		T& operator*()
		{
			if (!data)
				throw NullReferenceException();

			return *data;
		}

		const T* const operator->() const
		{
			if (!data)
				throw NullReferenceException();

			return data;
		}

		T* operator->()
		{
			if (!data)
				throw NullReferenceException();

			return data;
		}

		Box<T>& operator=(const T& value)
		{
			if (!data)
			{
				data = new T(value);
				ref_count = new size_t(1);
			}
			else
			{
				*data = value;
			}

			return *this;
		}

		Box<T>& operator=(T&& value)
		{
			if (!data)
			{
				data = new T(value);
				ref_count = new size_t(1);
			}
			else
			{
				*data = value;
			}

			return *this;
		}

		Box<T>& operator=(std::nullptr_t null)
		{
			if (data)
			{
				data = nullptr;
				delete ref_count;
				ref_count = nullptr;
			}

			return *this;
		}

		bool operator==(const Box<T>& box)
		{
			return *box == **this;
		}

		bool operator==(std::nullptr_t null)
		{
			return data == nullptr;
		}

		inline bool operator!=(const Box<T>& box)
		{
			return !this->operator==(box);
		}

		inline bool operator!=(std::nullptr_t null)
		{
			return !this->operator==(null);
		}

	public:
		const T& Get() const
		{
			if (!data)
				throw NullReferenceException();

			return *data;
		}

		T& Get()
		{
			if (!data)
				throw NullReferenceException();

			return *data;
		}

		const T* const Data() const
		{
			if (!data)
				throw NullReferenceException();

			return data;
		}

		T* Data()
		{
			if (!data)
				throw NullReferenceException();

			return data;
		}

		Box<T>& Set(const T& value)
		{
			if (!data)
			{
				data = new T(value);
				ref_count = new size_t(1);
			}
			else
			{
				*data = value;
			}

			return *this;
		}

		Box<T>& Set(T&& value)
		{
			if (!data)
			{
				data = new T(value);
				ref_count = new size_t(1);
			}
			else
			{
				*data = value;
			}

			return *this;
		}

		Box<T>& Set(std::nullptr_t null)
		{
			if (data)
			{
				data = nullptr;
				delete ref_count;
				ref_count = nullptr;
			}

			return *this;
		}
	};
}

#endif