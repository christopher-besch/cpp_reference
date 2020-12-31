#include <iostream>

#include "Log.h"

int main()
{
	Log("Hello World!");
	std::cin.get();
}

/*
header files:
	used to declare functions
	get included in .cpp files

declaration:
	show that a function exists

#pragma once:
	only include this file once
	header guard
	prevents problems double definitions of symbols e.g. functions
	legacy version:
		#ifndef _LOG_H
		#define _LOG_H
		// declarations
		#endif

# include <file> <- from include paths
# include "file" <- from relative path (and from include paths)

iostream without extension <- differentiate C and C++ standard library
*/
