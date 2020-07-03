#include <iostream>

int main()
{
	int variable = 8;
	//                 <- f marks float
	float myFloat = 5.5f;

	std::cout << sizeof(int) << std::endl;
	std::cin.get();
}

/*
difference between simple variable types is only their size

unsigned = without minus or plus

the size of each variable type depends on compiler

sizeof([type]) returns size in bytes

char
	1byte
short
	2bytes
int
	4bytes
	~(-2G -> +2G)
long
	4bytes
long long
	8bytes

float
	4bytes
double
	8bytes

bool
	1byte

pointers are defined with an asterisk after the type
references with an ampersand


*/
