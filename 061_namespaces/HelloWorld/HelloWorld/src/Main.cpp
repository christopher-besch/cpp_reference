#include <iostream>
#include <vector>
#include <functional>

#define LOG(msg) std::cout << msg <<std::endl


namespace test {
	// symbol
	template <typename type>
	void print(type msg)
	{
		LOG(msg);
	}
}



int main()
{
	// applies to scope
	using namespace test;
	// or
	// using test::print;
	namespace a = test;
	
	test::print("Hello World!");
	print("Hello World!");
	a::print("Hello World!");

	std::cin.get();
}

/*
 * C doesn't have namespaces, C++ does
 * namespaces can be nested
 * classes are namespaces too -> :: used too sometimes
 *
 * NEVER in header files!!!
 */
