#include <iostream>
#include <thread>
#include <chrono>

#define LOG(msg) std::cout << msg << std::endl


class Timer
{
private:
	std::chrono::time_point<std::chrono::steady_clock> start, end;
	std::chrono::duration<float> duration;
public:
	Timer()
	{
		this->start = std::chrono::high_resolution_clock::now();
	}

	~Timer()
	{
		this->end = std::chrono::high_resolution_clock::now();
		this->duration = end - start;

		float duration_ms = duration.count() * 1000.0f;
		LOG("Timer took " << duration_ms << "ms");
	}
};


void function()
{
	// this scope will now be timed
	Timer timer;
	
	for (int i = 0; i < 100; i++)
	{
		LOG("Hello!");
	}
}


int main()
{
	using namespace std::literals::chrono_literals;
	
	const auto start = std::chrono::high_resolution_clock::now();
	std::this_thread::sleep_for(1s);
	const auto end = std::chrono::high_resolution_clock::now();

	const std::chrono::duration<float> duration = end - start;

	LOG(duration.count());

	function();

	std::cin.get();
}

/*
 * query performance timer on windows
 * thread sleeps are not very precise
 * platform specific timer is a bit more precise
 */
