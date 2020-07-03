#include <iostream>
#include <array>

#define LOG(msg) std::cout << msg <<std::endl


int main()
{
	// actually a pointer type
	static const int len = 5;
	int example[len];
	int* ptr = example;
	
	example[0] = 16;
	// dereference ptr with offset of two integers with *
	*(ptr + 2) = 6;
	// cast into type with length of one byte and then cast back into int
	*(int*)((char*)ptr + 3 * sizeof(int)) = 7;
	
	example[4] = 4;

	// how to get the amount of entities in an array that is stack allocated
	// but not trustworthy
	int size = sizeof(example) / sizeof(int);

	for (int idx = 0; idx < 5; idx++)
	{
		LOG(example[idx]);
	}

	int* another = new int[5];

	for (int idx = 0; idx < 5; idx++)
	{
		another[idx] = 2;
	}

	delete[] another;

	// heavier way of doing it, takes care of size and bounce checking -> overhead
	std::array<int, 5> anotherNother;

	
	for (int idx = 0; idx < anotherNother.size(); idx++)
	{
		anotherNother[idx] = 2;
		LOG(anotherNother[idx]);
	}
	
	std::cin.get();
}
