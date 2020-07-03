#include <iostream>

#define LOG(msg) std::cout << msg <<std::endl


class Vector3
{
public:
	float x, y, z;
public:
	Vector3()
		: x(10), y(20), z(30) {}
};


int main()
{
	// allocated on stack;
	int value = 5;
	int array[5];
	array[1] = 2;
	array[2] = 3;
	array[3] = 4;
	array[4] = 5;
	array[0] = 1;
	Vector3 vector;

	// allocated on heap
	int* hvalue = new int;
	*hvalue = 5;
	int* harray = new int[5];
	harray[0] = 1;
	harray[1] = 2;
	harray[2] = 3;
	harray[3] = 4;
	harray[4] = 5;
	Vector3* hvector = new Vector3;

	delete hvalue;
	delete[] harray;
	delete hvector;

	std::cin.get();
}

/*
 * new calls malloc
 * allocate on stack -> one cpu instruction
 * allocate on heap -> big stuff
 */