#ifndef SYSTEM_FUNC_H
#define SYSTEM_FUNC_H

#include <functional>

namespace System
{
	template <typename TResult, typename... Args>
	using Func = std::function<TResult(Args...)>;
}

#endif