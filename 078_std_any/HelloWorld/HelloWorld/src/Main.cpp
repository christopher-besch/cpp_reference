#include <iostream>
#include <any>
#include <string>

#define LOG(msg) std::cout << msg << std::endl


int main()
{
	std::any data;
	data = 2;
	data = "Cherno";

	std::string string = std::any_cast<std::string>(data);
	
	std::cin.get();
}

/*
 * variant are just a type safe union
 */
