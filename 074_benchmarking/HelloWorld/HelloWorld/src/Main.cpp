#include <iostream>
#include <memory>
#include <chrono>
#include <array>

#define LOG(msg) std::cout << msg << std::endl


class Timer
{
private:
	std::chrono::time_point<std::chrono::high_resolution_clock> m_start_time_point;
public:
	Timer()
	{
		m_start_time_point = std::chrono::high_resolution_clock::now();
	}
	
	~Timer()
	{
		stop();
	}

	void stop()
	{
		auto end_time_point = std::chrono::high_resolution_clock::now();

		auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_start_time_point).time_since_epoch().count();
		auto end = std::chrono::time_point_cast<std::chrono::microseconds>(end_time_point).time_since_epoch().count();

		auto duration = end - start;
		double ms = duration * 0.001;

		LOG(ms);
	}
};


int main()
{
	{
		Timer timer;
		
		int value = 0;
		for (int i = 0; i < 1000000; i++)
		{
			value += 2;
		}
		LOG(value);
	}

	struct Vector2
	{
		float x, y;
	};

	LOG("make shared");
	// way faster then new shared
	{
		std::array<std::shared_ptr<Vector2>, 1000> shared_ptrs;
		Timer timer;
		for (int i = 0; i < shared_ptrs.size(); i++)
			shared_ptrs[i] = std::make_shared<Vector2>();
	}
	LOG("new shared");
	{
		std::array<std::shared_ptr<Vector2>, 1000> shared_ptrs;
		Timer timer;
		for (int i = 0; i < shared_ptrs.size(); i++)
			shared_ptrs[i] = std::shared_ptr<Vector2>(new Vector2);
	}
	LOG("make unique");
	{
		std::array<std::unique_ptr<Vector2>, 1000> shared_ptrs;
		Timer timer;
		for (int i = 0; i < shared_ptrs.size(); i++)
			shared_ptrs[i] = std::make_unique<Vector2>();
	}

	__debugbreak();

	std::cin.get();
}

/*
 * Resource acquisition is initialization RAII
 */
