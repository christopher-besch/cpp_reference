#include <iostream>
#include <string>
// used to make tuple
#include <utility>
// tuple is inside here
#include <tuple>

#define LOG(msg); std::cout << msg << std::endl;


int main()
{	
	// array test
	int x[5] = {1, 2, 3, 4};
	
	LOG(*x + 1);

	std::cin.get();
}


/*
 * options to return multiple values:
 *	- variables in struct or class
 *	- change referenced variable (by reference)
 *		good performance
 *	- change referenced variable (by pointer)
 *		nullptr can be used
 *	- array
 *		allocated in heap -> slow
 */
