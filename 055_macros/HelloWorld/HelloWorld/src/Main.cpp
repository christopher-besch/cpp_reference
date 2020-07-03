#include <iostream>
#include <string>

// can be written everywhere
#if DEBUG == 1
#define LOG(msg) std::cout << msg <<std::endl
#else
#define LOG(msg)
#endif
// this should NOT be done!
// #define WAIT std::cin.get()


int main()
{
	LOG("Hello World!");

	std::cin.get();
}

/*
 * add "DEBUG=1" to Preprocessor Definitions und Solution Properties -> C/C++ -> Preprocessor
 * multiple lines need "\" at the end -> escaping newline character
 */
