﻿#ifndef SYSTEM_COLLECTIONS_GENERIC_IENUMERABLE_H
#define SYSTEM_COLLECTIONS_GENERIC_IENUMERABLE_H

#include "_IEnumerable.h"

namespace System
{
	namespace Collections
	{
		namespace Generic
		{
			template <typename T>
			interface IEnumerable : public Collections::IEnumerable
			{
			};
		}
	}
}

#endif