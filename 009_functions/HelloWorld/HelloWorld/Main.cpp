#include <iostream>

int Multiply(int a, int b)
{
	return a * b;
}

void MultiplayAndLog(int a, int b)
{
	int result = Multiply(a, b);
	std::cout << result << std::endl;
}

int main()
{
	MultiplayAndLog(3, 2);
	MultiplayAndLog(7, 9);
	MultiplayAndLog(69, 42);

	std::cin.get();
}

/*
functions are not part of a class
prevent code duplication

the compiler might inline a function
*/
