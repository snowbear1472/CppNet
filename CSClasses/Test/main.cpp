#define LANG_KOR
#define WIN32

#include <string>
#include <CSClasses\CSClasses.h>

using namespace std;
using namespace System;
using namespace System::Collections::Generic;

int main(void)
{
	cout.imbue(locale(""));
	cin.imbue(locale(""));

	const char* temp = u8"��";

	cout << temp << endl;

	Queue<int> queue;
	queue.Enqueue(3);
	queue.Enqueue(4);
	var enumerator = queue.GetEnumerator();
	while (enumerator->MoveNext())
	{
		Console::WriteLine(enumerator->Current());
	}

	var arr = BitConverter::GetBytes(50000000000);
	
	var chr = BitConverter::ToInt64(arr);

	Console::WriteLine(chr);

	Console::WriteLine(DoubleT::Zero.Data());
	Console::WriteLine(DoubleT::NaN.Data());

	Console::WriteLine(DoubleT::IsNaN(DoubleT::NaN));

	Console::WriteLine(DoubleT::PositiveInfinity.Data());
	Console::WriteLine(DoubleT::NegativeInfinity.Data());
	Console::WriteLine(DoubleT::MaxValue.Data());
	Console::WriteLine(DoubleT::MinValue.Data());
	Console::WriteLine(DoubleT::Epsilon.Data());

	var a = BitConverter::GetBytes(std::numeric_limits<UInt64>::max());

	var c = BitConverter::BytesToHexString(a);

	Console::WriteLine(c);

	var a2 = BitConverter::HexStringToBytes<8>(c);

	Console::WriteLine(BitConverter::ToInt64(a2));

	Char �m(u8"��", 3);
	
	Console::WriteLine(�m);

	MAIN_END
}