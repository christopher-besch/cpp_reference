#include <iostream>
#include <string>

#include <stdlib.h>

#define LOG(msg) std::cout << msg <<std::endl


class Entity
{
private:
	std::string m_Name;
public:
	Entity()
		: m_Name("Unknown") {}
	Entity(const std::string& name) : m_Name(name) {}

	const std::string& GetName() const
	{
		return m_Name;
	}
};


int main()
{
	int a = 2;
	// allocated on the heap
	int* b = new int[50]; // 200 bytes

	Entity* e = new Entity();

	// new can take a pointer at which to store the data as a parameter
	// Entity* e = new(b) Entity();

	// used to free memory from an array
	delete[] b;
	delete e;



	int* c = new int;
	// change dereferenced value
	*c = 5;

	// dereferencing
	LOG(*c);
	LOG(c);
	// referencing
	LOG(&c);
	
	
	std::cin.get();
}

/*
 *new allocates space on the heap
 *new takes time
 *new doesn't just allocate memory, it also calls the constructor
 *new is just an operator and therefor can be overloaded
 *new usually calls the c function malloc, which returns a pointer to memory of a specific size ->
 *Entity* e = new Entity(); does pretty much the same as Entity* e = (Entity*)malloc(sizeof(Entity));
 *
 *delete MUST be used
 *delete also calls the destructor
 */
