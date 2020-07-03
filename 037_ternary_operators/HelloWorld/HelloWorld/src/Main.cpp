#include <iostream>
#include <string>

#include <stdlib.h>

#define LOG(msg) std::cout << msg <<std::endl

static int s_Level = 1;
static int s_Speed = 2;


int main()
{
	if (s_Level > 5)
	{
		s_Speed = 10;
	}
	else
	{
		s_Speed = 5;
	}

	for (int idx = 0; idx < 10; idx++)
	{
		s_Level = idx;

		// this does the same as the code before the for loop
		s_Speed = s_Level > 5 ? 10 : 5;
		
		LOG(s_Speed);
	}

	std::cin.get();
}

/*
 *ternary operators might be faster because of return value optimization
 */
