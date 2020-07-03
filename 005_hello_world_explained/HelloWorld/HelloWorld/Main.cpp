// preprocessor statement start with #
#include <iostream>

// declaration
//                   <- name of the parameter optional
void Log(const char* message);

int main()
{
	// call function
	Log("Hello World!");
	// waiting for input
	std::cin.get();
}

/*
compiler:
	turns c++ code into machine code
linker:
	glues object files together (-> .exe)

x86 == win32
each .cpp file gets compiled -> object file (.obj)
header files don't get directly compiled
*/
