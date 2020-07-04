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
* optimizations might remove branching
*
* new project -> Visual C++ -> General -> Empty Project
* click on project -> show all files icon
* create folder src (move every .cpp in there)
* project properties -> edit all configurations
* under Configuration Properties -> General
*	$(SolutionDir)bin\$(Platform)\$(Configuration)\ in Output Directory
*	$(SolutionDir)bin\intermediates\$(Platform)\$(Configuration)\ in Intermediate Directory
*/
