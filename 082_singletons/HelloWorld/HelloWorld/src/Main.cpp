#include <iostream>
#include <string>
#include <chrono>

#define LOG(msg) std::cout << msg << std::endl


// singleton
class Random
{
private:
	// would have to be declared outside of the class -> replaced by static Random instance; in get()
	// static Random s_instance;
	float m_random_number = 0.5f;
public:
	// delete copy constructor
	Random(const Random&) = delete;

	static Random& get()
	{
		static Random instance;
		return instance;
	}

	// actual meat -> code
	float random_float()
	{
		return m_random_number;
	}
	// or
	static float random_float2()
	{
		return get().i_random_float();
	}
private:
	// disable constructor
	Random() {};
	
	// actual meat -> code
	float i_random_float()
	{
		return m_random_number;
	}
};


int main()
{
	float number = Random::get().random_float();
	LOG(number);
	// or
	float number2 = Random::random_float2();
	LOG(number2);
	
	std::cin.get();
}

/*
 * singletons are the instance of a class that is intended to only have one instance
 * singletons can just behave like a namespace
 * singletons are a way of structuring a set of global variables and / or static functions
 */
