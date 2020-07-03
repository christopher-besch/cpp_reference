// preprocessor statement start with #
#include <iostream>

// declaration
//                   <- name of the parameter optional
void Log(const char* message);

int main()
{
	// call function
	Log("Hello World!");
	int x = 0;
	x / x;
	// waiting for input
	std::cin.get();
}

/*
preprocessing:
	examples:
		#include "file_location"
			paste content from file_location to statement
		#define x y
			replaces every occurrence of the first word (x) by the second word (y)
		#if
		#ifdef

compiling:
	turns c++ code (.cpp files) into machine code

linking:
	glues object files together (-> .exe)
	utilizes function signature

x86 == win32
each .cpp file gets compiled -> object file (.obj)
.cpp file (with every #include) = translation unit
header files don't get directly compiled

optimization not in debug (e.g. constant folding)

linking error = duplicate symbols or missing symbols
*/
