#include <iostream>
#include <string>
#include <chrono>

#include "Instrumentor.h"

#define LOG(msg) std::cout << msg << std::endl

#define PROFILING 1
// define PROFILE_SCOPE and PROFILE_FUNCTION when PROFILING is 1
#if PROFILING
#define PROFILE_SCOPE(name) InstrumentationTimer timer##__LINE__(name)
//                                       <- returns name, parameters, result types and other stuff of the function this macro is used in (__FUNCTION__ returns only the name)
#define PROFILE_FUNCTION() PROFILE_SCOPE(__FUNCSIG__)
#else
#define PROFILE_SCOPE(name)
#define PROFILE_FUNCTION()
#endif


void function1()
{
	PROFILE_FUNCTION();

	for (int i = 0; i < 1000; i++)
		LOG("Hello World #" << i);
}


void function2()
{
	PROFILE_FUNCTION();

	for (int i = 0; i < 1000; i++)
		LOG("Hello World #" << sqrt(i));
}


void run_benchmarks()
{
	PROFILE_FUNCTION();

	LOG("running benchmarks...");

	function1();
	function2();
}


int main()
{
	Instrumentor::Get().BeginSession("My Session");
	
	run_benchmarks();

	Instrumentor::Get().EndSession();
	
	std::cin.get();
}
