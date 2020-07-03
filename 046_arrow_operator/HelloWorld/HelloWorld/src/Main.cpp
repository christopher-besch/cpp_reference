#include <iostream>
#include <string>
#include <memory>

#include <stdlib.h>

#define LOG(msg) std::cout << msg <<std::endl


class Entity
{
public:
	void Print() const
	{
		LOG("Hello!");
	}
};


class ScopedPtr
{
private:
	Entity* m_Obj;
public:
	ScopedPtr(Entity* entity)
		: m_Obj(entity) {}

	~ScopedPtr()
	{
		delete m_Obj;
	}

	Entity* operator->()
	{
		return m_Obj;
	}
};


struct Vector3
{
	float x, y, z;
};


int main()
{
	Entity e;
	e.Print();

	Entity* ptr = &e;
	(*ptr).Print();
	ptr->Print();


	ScopedPtr entity = new Entity();
	entity->Print();

	int offset = (int)&((Vector3*)nullptr)->y;
	LOG(offset);

	std::cin.get();
}


/*
 * 
 */
