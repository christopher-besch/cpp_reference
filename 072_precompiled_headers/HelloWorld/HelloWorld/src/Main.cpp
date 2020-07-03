#include "pch.h"

#define LOG(msg) std::cout << msg << std::endl


int main()
{
	LOG("Hello World!");

	std::cin.get();
}

/*
 * precompiled headers can substantially reduce compile times
 * it takes a couple of header files and compiles it into a precompiled state
 * things that change rarely only should be put in the pch
 * vitally useful for external code used often (like stl <- vectors, strings)
 */
