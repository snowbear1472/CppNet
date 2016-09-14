#ifndef SYSTEM_IFORMATPROVIDER_H
#define SYSTEM_IFORMATPROVIDER_H

#include "Object.h"
#include "Utility.h"

namespace System
{
	interface IFormatProvider
	{
		virtual inline Object GetFormat(Int32 type_id) = 0;
	};
}

#endif