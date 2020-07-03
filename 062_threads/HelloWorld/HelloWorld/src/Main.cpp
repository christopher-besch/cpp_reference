#include <iostream>
#include <thread>

#define LOG(msg) std::cout << msg <<std::endl


static bool s_finished = false;


void do_work()
{
	using namespace std::literals::chrono_literals;

	LOG("Started thread id = " << std::this_thread::get_id());
	
	while (!s_finished)
	{
		LOG("Working...");
		std::this_thread::sleep_for(1s);
	}
}


int main()
{
	LOG("Started thread id = " << std::this_thread::get_id());

	//                 <- takes function pointer
	std::thread worker(do_work);

	std::cin.get();
	s_finished = true;
	
	// wait on current thread until worker is done
	worker.join();
	LOG("Finished");

	std::cin.get();
}

/*
 * threads are mainly used for optimization or making things like this possible (actually only easier)
 */
