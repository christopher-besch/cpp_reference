#include <iostream>
#include <string>

#include <stdlib.h>

#define LOG(msg) std::cout << msg <<std::endl


class Entity
{
private:
	std::string m_Name;
	// DEBUG ONLY!!!
	mutable int m_DebugCount = 0;
	
public:
	const std::string& GetName() const
	{
		m_DebugCount++;
		return m_Name;
	}
};


int main()
{
	const Entity e;
	e.GetName();

	int x = 8;

	// using no variables
	// auto f = []()
	
	// using every variable by reference
	// auto f = [&]()

	// using every variable by value
	// auto f = [=]()

	// mutable lambda (throw-away-function) -> every variable parsed by value is copied -> can be changed
	auto f = [=]() mutable
	{
		x++;
		LOG("Hello World!");
		LOG(x);
	};

	std::cin.get();
}

/*
 *
 */
