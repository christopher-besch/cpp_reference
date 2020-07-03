#include <iostream>

#define LOG(msg) std::cout << msg << std::endl


class Entity
{
public:
	int x, y;
};


int main()
{
	int a = 50;
	// implicit conversion
	double value = a;
	// same as
	// double value = double(a);
	// or
	// double value = (double)a;
	LOG(value);

	// type punning
	// converting int pointer into double pointer and dereferencing it
	// not good because int is smaller than double
	double a_as_double = *(double*)&a;
	// or as reference
	// double& a_as_double = *(double*)&a;
	LOG(a_as_double);

	Entity e = { 5, 8 };
	int* position = (int*)&e;
	LOG(position[0]);
	LOG(((int*)&e)[0]);
	// ridiculous!!!
	LOG(*(int*)((char*)&e + 4));

	std::cin.get();
}

/*
 * C++ is a strongly typed language -> except for auto there is a type system
 * type punning -> treat memory as a different type
 */
