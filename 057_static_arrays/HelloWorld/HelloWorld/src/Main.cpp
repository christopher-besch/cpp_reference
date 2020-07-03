#include <iostream>
#include <array>

#define LOG(msg) std::cout << msg <<std::endl


// void PrintArray(const std::array<int, 5>& data)
template <int Size>
void PrintArray(const std::array<int, Size>& data)
{
	for (int idx = 0; idx < data.size(); idx++)
	{
		LOG(data[idx]);
	}
}


int main()
{
	std::array<int, 5> data;
	data[0] = 2;
	data[4] = 1;
	// causes crash in DEBUG
	// data[5] = 1;

	PrintArray<5>(data);
	PrintArray(data);

	std::cin.get();
}

/*
 * static arrays don't grow or shrink
 * stored on stack
 * bounce checking
 *
 * should be used everywhere
 */
