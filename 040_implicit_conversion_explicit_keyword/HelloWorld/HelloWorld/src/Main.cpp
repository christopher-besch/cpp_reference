#include <iostream>
#include <string>

#include <stdlib.h>

#define LOG(msg) std::cout << msg <<std::endl


class Entity
{
private:
	std::string m_Name;
	int m_Age;
public:
	Entity(const std::string& name)
		: m_Name(name), m_Age(-1) {}
	
	// explicit Entity(int age) <- this would disallow any implicit conversion with this constructor
	Entity(int age)
		: m_Name("Unknown"), m_Age(age) {}
};


int main()
{
	// implicitly converting int into Entity
	Entity b = 22;

	// doesn't work for some reason
	Entity a = "Cherno";
	// should be same as
	// Entity a = Entity("Cherno");
	// Entity b = Entity(22);

	std::cin.get();
}

/*
 *c++ is only allowed to do one implicit conversion
 *implicit conversion should be avoided
 */
