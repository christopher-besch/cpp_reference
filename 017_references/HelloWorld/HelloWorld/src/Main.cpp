#include <iostream>

#define LOG(msg) std::cout << msg <<std::endl


void Increment(int& value)
{
	value++;
}


int main()
{
	int a = 5;
	Increment(a);
	LOG(a);

	std::cin.get();
}


/*
you can't change the value of a reference, you would only change the referenced variable
it has to be assigned immediately
*/
