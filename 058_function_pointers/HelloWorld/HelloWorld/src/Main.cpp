#include <iostream>
#include <array>

#define LOG(msg) std::cout << msg <<std::endl


void HelloWorld(int x)
{
	LOG("Hello World!");
	LOG(x);
}


int main()
{
	// first option
	void(*funcName)(int);
	funcName = &HelloWorld;

	// second option
	// retrieve memory location of the function
	auto function = &HelloWorld;

	// third option
	typedef void(*HelloWorldFunction)(int);
	HelloWorldFunction func3 = &HelloWorld;

	function(1);
	function(2);
	function(3);

	funcName(4);
	funcName(5);
	funcName(6);

	func3(7);
	func3(8);
	func3(9);

	std::cin.get();
}

/*
 * for (int value : values)
 */
