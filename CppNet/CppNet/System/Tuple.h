#ifndef SYSTEM_TUPLE_H
#define SYSTEM_TUPLE_H

#include <tuple>

namespace System
{
	template<typename... Args>
	using Tuple = std::tuple<Args...>;
}

#endif