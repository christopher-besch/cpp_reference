#include <iostream>

#define LOG(msg) std::cout << msg <<std::endl

int main()
{
	// void* ptr = nullptr;

	int var = 8;
	// &var returns the memory address of var
	int* ptr = &var;
	// dereferencing
	*ptr = 10;
	LOG(*ptr);
	LOG(var);

	std::cin.get();
}


/*
pointers are just numbers
a NULL pointer is invalid
*/