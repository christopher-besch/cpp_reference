#include <iostream>
#include <string>

#include <stdlib.h>

#define LOG(msg) std::cout << msg <<std::endl


class Entity
{
private:
	std::string m_Name;
	int m_Score;
	
public:
	Entity()
		// keep the order the variables are declared in
		: m_Name("Unknown"), m_Score(0)
	{
		// m_Name gets constructed twice, once with the default constructor (no value) and another time with "Unknown"
		// wasted cpu cycles
		m_Name = "Unknown";
		// this actually happens
		m_Name = std::string("Unknown");
	}
	
	Entity(const std::string& name)
	{
		m_Name = name;
	}
	
	const std::string& GetName() const
	{
		return m_Name;
	}
};


int main()
{
	Entity e;
	LOG(e.GetName());

	Entity e1("TEST");
	LOG(e1.GetName());

	Entity e2;
	LOG(e2.GetName());

	std::cin.get();
}

/*
 *constructor member initializer lists might look cleaner and should be used everywhere
 */
