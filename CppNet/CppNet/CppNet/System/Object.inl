#include "Object.h"

namespace CppNet
{
	namespace System
	{
		Boolean Object::Equals(const Object& obj) const
		{
			return obj == *const_cast<Object*>(this);
		}

		Boolean Object::Equals(const Object& obj, const Object& obj2)
		{
			return obj.Equals(obj2);
		}

		Boolean Object::ReferenceEquals(Object& obj, Object& obj2)
		{
			if (&obj == &obj2) return true;
			else return false;
		}

		String Object::ToString() const
		{
			return "";
		}
	}
}