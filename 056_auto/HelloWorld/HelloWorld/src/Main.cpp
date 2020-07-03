#include <iostream>
#include <string>
#include <vector>

#define LOG(msg) std::cout << msg <<std::endl


std::string GetName()
{
	return "Cherno";
}


int main()
{
	auto b = 5;

	LOG(b);

	std::vector<std::string> strings;
	strings.push_back("Apple");
	strings.push_back("Orange");

	for (auto iterator = strings.begin(); iterator != strings.end(); iterator++)
	// same as
	// for (std::vector<std::string>::iterator iterator = strings.begin(); iterator != strings.end(); iterator++)
	{
		LOG(*iterator);
	}
	// using Iterator = std::vector<std::string>::iterator
	// or
	// typedef std::vector<std::string>::iterator Iterator
	// could be used instead

	std::cin.get();
}

/*
 * auto replaces the variable type definition and automatically detects the right one
 * reference with auto -> auto&
 */
