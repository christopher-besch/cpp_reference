#include <iostream>
#include <string>

#define LOG(msg) std::cout << msg <<std::endl


int main()
{
	// C version
	// double quotes -> string
	// single quotes -> char
	const char* name = "TEST";
	strlen(name);
	// '\0' or 0 -> NULL character
	char name2[5] = { 'T', 'E', 'S' , 'T', '\0' };
	LOG(name2);

	// C++ version
	// template specialization
	std::string name3 = "TEST";
	// += operator is overloaded
	name3 += " HIHIHI";

	// name3.find() returns position of result or std::string::npos
	bool contains = name3.find("TE") != std::string::npos;
	
	name3.size();
	LOG(name3);

	std::cin.get();
}
