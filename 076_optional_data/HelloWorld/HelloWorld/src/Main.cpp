#include <iostream>
#include <fstream>
#include <string>
#include <optional>

#define LOG(msg) std::cout << msg << std::endl

// C++ 17 required
std::optional<std::string> read_file_as_string(const std::string& filepath)
{
	std::ifstream stream(filepath);
	if (stream)
	{
		std::string result;
		// read file
		stream.close();
		return result;
	}

	return {};
}


int main()
{
	std::optional<std::string> data = read_file_as_string("data.txt");
	if (data)
	// same as
	// if (data.has_value())
	{
		LOG("File read successfully!");

		std::string& string = *data;
		// almost same as
		std::string string2 = data.value();
		
	} else
	{
		LOG("File could not be opened!");
	}

	std::string value = data.value_or("Not present");
	
	std::cin.get();
}
