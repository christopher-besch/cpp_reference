#include <iostream>

#include "Log.h"

int main()
{
	for (int i = 0; i < 5; i++)
	{
		if (i < 2)
			continue;

		Log(i);
	}

	std::cin.get();
}
