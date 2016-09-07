
/*
	2016.09.07
	Created by kmc7468
*/

#ifndef SYSTEM_CONSOLE_H

#define SYSTEM_CONSOLE_H

#include "System.h"

#include <iostream>
<<<<<<< HEAD
=======
#include <string>
>>>>>>> 5bc4e91b262187aedcb580a5cce96bb776f1aabe

namespace System
{
	class Console final : public Object
	{
	public:
		Console() = default;
		Console(Console &&sNewConsole) = delete;
		Console(const Console &sNewConsole) = delete;
		~Console() = default;

	public:
		Console &operator=(Console &&sNewConsole) = delete;
		Console &operator=(const Console &sNewConsole) = delete;

	public:
		static inline void Write(Boolean boolean)
		{
			std::wcout << boolean;
		}

		static inline void Write(Char character)
		{
			std::wcout << character;
		}

		static inline void Write(String string)
		{
			std::wcout << string;
		}

		static inline void Write(String string, Int32 index, Int32 count)
		{
<<<<<<< HEAD
			std::wcout.write(string.c_str() + index, count);
=======
			std::wcout << string.substr(index, count);
>>>>>>> 5bc4e91b262187aedcb580a5cce96bb776f1aabe
		}

		static inline void Write(Double doubled)
		{
			std::wcout << doubled;
		}

		static inline void Write(Int32 integer)
		{
			std::wcout << integer;
		}

		static inline void Write(Int64 integer)
		{
			std::wcout << integer;
		}

		static inline void Write(Single single)
		{
			std::wcout << single;
		}

		static inline void Write(UInt32 integer)
		{
			std::wcout << integer;
		}

		static inline void Write(UInt64 integer)
		{
			std::wcout << integer;
		}

		static inline void WriteLine()
		{
			std::wcout << std::endl;
		}

		static inline void WriteLine(Boolean boolean)
		{
			std::wcout << boolean << std::endl;
		}

		static inline void WriteLine(Char character)
		{
			std::wcout << character << std::endl;
		}

		static inline void WriteLine(String string)
		{
			std::wcout << string << std::endl;
		}

		static inline void WriteLine(String string, Int32 index, Int32 count)
		{
<<<<<<< HEAD
			std::wcout.write(string.c_str() + index, count) << std::endl;
=======
			std::wcout << string.substr(index, count) << std::endl;
>>>>>>> 5bc4e91b262187aedcb580a5cce96bb776f1aabe
		}

		static inline void WriteLine(Double doubled)
		{
			std::wcout << doubled << std::endl;
		}

		static inline void WriteLine(Int32 integer)
		{
			std::wcout << integer << std::endl;
		}

		static inline void WriteLine(Int64 integer)
		{
			std::wcout << integer << std::endl;
		}

		static inline void WriteLine(Single single)
		{
			std::wcout << single << std::endl;
		}

		static inline void WriteLine(UInt32 integer)
		{
			std::wcout << integer << std::endl;
		}

		static inline void WriteLine(UInt64 integer)
		{
			std::wcout << integer << std::endl;
		}
<<<<<<< HEAD
=======

		static inline String ReadLine()
		{
			String str;
			std::getline(std::wcin, str);
			return str;
		}

		// TODO Read
>>>>>>> 5bc4e91b262187aedcb580a5cce96bb776f1aabe
	};
}

#endif