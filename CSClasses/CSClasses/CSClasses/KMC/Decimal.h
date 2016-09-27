#ifndef CSCLASSES_KMC_DECIMAL_H
#define CSCLASSES_KMC_DECIMAL_H

#include "../../SystemTypes.h"
#include "../../Queue.h"
#include <vector>
using namespace::System;
using namespace::System::Collections::Generic;

namespace CSClasses
{
	namespace KMC
	{
		class Decimal final : public Object
		{
		private:
			class ByteTool final
			{
			public:
				static inline Byte IntsToByte(Byte a, Byte b);
				static inline std::tuple<Byte, Byte> ByteToInts(Byte b);
				static inline Byte ToByte(char c);
				static inline char FromByte(Byte b);
			};

		private:
			typedef std::basic_string<Byte, std::char_traits<Byte>, std::allocator<Byte>> t;

		private:
			t mInteger;
			t mReal;
			Boolean isN = false;

		public:
			Decimal();
			Decimal(const String& str);
			Decimal(Int64 integer);
			Decimal(Int64 integer, const String& real);
			Decimal(Double real);
			Decimal(Decimal&& d);
			Decimal(const Decimal& d);
			~Decimal() = default;

		public:
			String ToString() const;
			inline String ToString(size_t realsize) const;

		public:
			Boolean operator==(const Object& obj) override;
			Boolean operator!=(const Object& obj) override;

		public:
			Decimal operator=(const Decimal& d);
			Decimal operator=(Decimal&& d);

			Decimal operator+(const Decimal& d) const;
			Decimal operator+(Decimal&& d) const;

			Decimal operator+=(const Decimal& d);
			Decimal operator+=(Decimal&& d);

			Decimal operator++();
			Decimal operator++(int);

			Decimal operator-(const Decimal& d) const;

		private:
			inline void Clean();
		};
	}
}

#include "Decimal.inl"

#endif