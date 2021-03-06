#ifndef SYSTEM_RANDOM_H
#define SYSTEM_RANDOM_H

#include "../../Defines.h"

#include "Int64.h"
#include "Int32.h"
#include "UInt32.h"
#include "Double.h"

#include "Object.h"

#include <random>

namespace CppNet
{
	namespace System
	{
		enum class RandomType
		{
			MT19937,
			MT19937_64,
			RANDOM_DEVICE,
		};

		class Random : public Object
		{
		public:
			Random(RandomType type = RandomType::MT19937);
			Random(RandomType type, UInt32 seed);
			Random(Random &&sNewRandom);
			Random(const Random &sNewRandom);
			~Random() = default;

		public:
			Random& operator=(Random &&sNewRandom);
			Random& operator=(const Random &sNewRandom);

		private:
			UInt32 seed;
			RandomType type;

		public:
			inline Int64 Next() const;
			inline Int64 Next(const Int64& max) const;
			inline Int32 Next(const Int32& max) const;
			inline Int64 Next(const Int64& min, const Int64& max) const;
			inline Int32 Next(const Int32& min, const Int32& max) const;

			// TODO NextBytes

			inline Double NextDouble() const;
			inline Double Sample() const;
		};
	}
}

#endif