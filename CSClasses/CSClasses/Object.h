

/*
	2016.09.07
	Created by kmc7468
*/

#ifndef SYSTEM_OBJECT_H
#define SYSTEM_OBJECT_H

#include "System.h"

namespace System
{
	class Object
	{
	public:
		virtual ~Object()
		{

		}
		
		virtual Boolean operator==(Object& obj)
		{
			if (&obj == this)
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		virtual inline Boolean Equals(Object& obj) const
		{
			return obj == *const_cast<Object*>(this);
		}

		virtual inline Boolean Equals(Object& obj, Object& obj2) const
		{
			return obj == obj2;
		}

		virtual inline String ToString() const
		{
			return L"";
		}
	};
}

#endif