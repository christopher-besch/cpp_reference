#include <iostream>
#include <string>
#include <chrono>

#define LOG(msg) std::cout << msg << std::endl


void print_sum(int a, int b)
{
	std::cout << a << " + " << b << " = " << (a + b) << std::endl;
}


int main()
{
	int value = 0;
	// undefined behaviour -> unreliable
	print_sum(value++, value++);
	
	std::cin.get();
}
