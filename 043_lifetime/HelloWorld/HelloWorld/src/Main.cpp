#include <iostream>
#include <string>

#include <stdlib.h>

#define LOG(msg) std::cout << msg <<std::endl


class Entity
{
public:
	Entity()
	{
		LOG("Created Entity!");
	}

	~Entity()
	{
		LOG("Destroyed Entity!");
	}
};


class ScopedPtr
{
private:
	Entity* m_Ptr;
public:
	explicit ScopedPtr(Entity* ptr)
		: m_Ptr(ptr) {}

	~ScopedPtr()
	{
		delete m_Ptr;
	}
};


int main()
{
	// scope
	{
		// created on the stack
		Entity e;
	}
	// Entity e gets destroyed

	{
		ScopedPtr e = ScopedPtr(new Entity());
	}

	std::cin.get();
}
