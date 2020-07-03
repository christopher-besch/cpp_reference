#include <iostream>
#include <string>
#include <chrono>

#define LOG(msg) std::cout << msg << std::endl


void* operator new(size_t size)
{
	LOG("allocating " << size << " bytes");
	return malloc(size);
}


int main()
{
	// no heap allocating, unless in debug
	std::string name = "Cherno";
	
	std::cin.get();
}

/*
 * small strings (in VS smaller than 16) don't need 
 */
