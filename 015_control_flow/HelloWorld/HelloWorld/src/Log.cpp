#include <iostream>

#include "Log.h"

void Log(const char* message)
{
	std::cout << message << std::endl;
}


void Log(const int message)
{
	std::cout << message << std::endl;
}
