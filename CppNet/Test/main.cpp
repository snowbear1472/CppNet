#include <CppNet/CppNet.h>

int main()
{
	Decimal a(1.5), b(1.0);
	Console::WriteLine((Boolean)(a > b));
	Console::WriteLine((a - b).ToString());
	
	MAIN_END
}