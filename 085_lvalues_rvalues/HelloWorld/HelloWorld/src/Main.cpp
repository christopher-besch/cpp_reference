#include <iostream>
#include <string>
#include <chrono>

#define LOG(msg) std::cout << msg << std::endl


// only takes rvalue reference <- rvalue reference
// known that the only used parameters is a (temporary) rvalue
// -> this value won't be used anywhere else -> the function is free to tinker with this value and its resources can be used
void print_temporary(std::string&& str)
{
	LOG(str);
}


int main()
{
	//  <- lvalue
	//      <- rvalue
	int i = 10;

	// this doesn't work
	// int& a = 10;
	// but this works -> compiler creates temporary lvalue
	const int& b = 10;

	//          <- lvalue
	//                       <- rvalue
	std::string first_name = "Yan";
	std::string last_name = "Chernikov";
	//                      <- rvalue
	std::string full_name = first_name + last_name;

	print_temporary(first_name + last_name);
	
	std::cin.get();
}

/*
 * lvalues:
 *	often on the left side of the equal sign
 * rvalues:
 *	often on the right side of the equal sign
 *	can't be referenced
 *	temporary
 */
