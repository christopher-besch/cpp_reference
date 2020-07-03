#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

#define LOG(msg) std::cout << msg << std::endl


int main()
{
	std::vector<int> values = { 8, 4, 3, 0, 9, 7, 5, 2, 1, 6 };
	// no function pointer -> sorting with operator <
	// std::sort(values.begin(), values.end(), [](int entry1, int entry2){ return entry1 > entry2; });
	// same as
	std::sort(values.begin(), values.end(), std::greater<int>());

	for (int entry : values)
	{
		LOG(entry);
	}

	std::cin.get();
}
