#include <iostream>
#include <memory>
#include <chrono>
#include <array>
#include <tuple>
#include <string>

#define LOG(msg) std::cout << msg << std::endl


std::tuple<std::string, int> create_person()
{
	return { "Cherno", 24 };
}


int main()
{
	auto person = create_person();
	std::string& name = std::get<0>(person);
	int age = std::get<1>(person);

	// other way of doing it
	std::string name2;
	int age2;
	std::tie(name2, age2) = create_person();

	// C++ 17 is required (under properties -> C/C++ -> Language -> C++ Language Standard)
	auto[name3, age3] = create_person();
	LOG(name3);
	LOG(age3);
	
	std::cin.get();
}
