#include <iostream>
#include <GLFW/glfw3.h>

#define LOG(msg) std::cout << msg <<std::endl


int main()
{
	int a = glfwInit();
	LOG(a);

	std::cin.get();
}

/*
 * static linking happens on compile time
 * dynamic linking happens on executable launch
 *
 * ToDO:
 * - same as with static linking (just with different .lib (e.g. glfw3dll.lib))
 * - paste file (e.g. glfw3.lib) into .exe folder 
*/
