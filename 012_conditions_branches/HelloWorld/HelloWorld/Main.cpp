#include <iostream>

#include "Log.h"

int main()
{
	int x = 5;
	if (x == 5)
	{
		Log("Hello World!");
	}

	std::cin.get();
}

/*
optimizations might remove branching
*/
