#include <iostream>
#include <string>

#include <stdlib.h>

#define LOG(msg) std::cout << msg <<std::endl

using String = std::string;

class Entity
{
private:
	String m_Name;
public:
	Entity()
		: m_Name("Unknown") {}
	Entity(const String& name)
		: m_Name(name) {}

	const String& GetName() const
	{
		return m_Name;
	}
};


void Function()
{
	int a = 2;
	Entity entity = Entity("TEST");
	// gets destroyed after end of this scope
}


int main()
{
	Entity* e;
	{
		// create in stack
		// calling default constructor
		Entity entity;
		// same as
		// Entity entity = Entity();
		LOG(entity.GetName());

		e = &entity;
	}

	Entity* e2;
	{
		Entity* entity2 = new Entity("Cherno");

		LOG(entity2->GetName());

		// survives stack pop
		e2 = entity2;
	}

	LOG(e2->GetName());
	
	delete e2;
	std::cin.get();
}

/*
 *there are different types types of memory: stack and heap (there are more, like the place the source code lives)
 *stack:
 *	automatic life time (variable out of scope -> variable dies (stack pops))
 *	should be used unless impossible -> fastest way
 *	1 to 2 MB ()
 *heap:
 *	variables stay
 *	takes longer
 *	you have to manually free that allocated memory -> no memory leaks
 */
