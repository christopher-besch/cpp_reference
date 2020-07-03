#include <iostream>
// "" with dependencies that are compiled in this solution, <> otherwise
#include <GLFW/glfw3.h>

#define LOG(msg) std::cout << msg <<std::endl

// extern "C" int glfwInit();


int main()
{
	int a = glfwInit();
	LOG(a);

	std::cin.get();
}

/*
 * you should compile yourself
 * there are static and dynamic libraries
 *
 * ToDo:
 * - download library binaries
 * - put them in folder [Project_Name]/Dependencies/[Dependency_Name]
 * - under the projects properties in "C/C++" -> General add $(SolutionDir)\Dependencies\[Dependency_Name]\include to the additional include directories
 * -> you can include relative to include folder
 * - under the projects properties in "Linker" -> General add $(SolutionDir)\Dependencies\[Dependency_Name]\lib-vc2019 to the additional library directories
 * -                                           -> Input add [Name_Of_Library_File] (e.g glfw3.lib) to the additional dependencies
*/
