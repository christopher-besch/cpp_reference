#include <iostream>
#include <future>
#include <vector>

#define LOG(msg) std::cout << msg << std::endl


void do_stuff(const int number)
{
	for (int i = 1; i < number + 1; i++)
	{
		do_stuff(number - 1);
	}
}


int main()
{
	LOG("sync");
	for (int i = 0; i < 15; i++)
	{
		do_stuff(10);
		LOG(i);
	}
	LOG("async");
	//                     <- return type of the function used
	std::vector<std::future<void>> futures;
	
	for (int i = 0; i < 15; i++)
	{
		futures.push_back(std::async(std::launch::async, do_stuff, 10));
		LOG(i);
	}
	
	
	std::cin.get();
}

/*
 * std::async is a wrapper around thread
 */
