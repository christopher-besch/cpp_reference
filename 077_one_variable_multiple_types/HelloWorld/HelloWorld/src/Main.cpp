#include <iostream>
#include <variant>
#include <string>

#define LOG(msg) std::cout << msg << std::endl


int main()
{
	std::variant<std::string, int> data;
	data = "Cherno";
	LOG(std::get<std::string>(data));
	data = 2;
	LOG(std::get<int>(data));

	LOG(data.index()); // -> 1 <- int is second type specified

	if (auto value = std::get_if<std::string>(&data))
	{
		LOG(*value);
	}
	
	std::cin.get();
}

/*
 * kind of similar to unions but both variables don't use the same memory
 */
