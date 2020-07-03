#include <iostream>

extern int sVariable = 10;

int main()
{
	std::cout << sVariable << std::endl;
}


/*
static can prevent linking errors
use static as much as possible unless link between translation units necessary
*/
