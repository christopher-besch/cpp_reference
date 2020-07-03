#include <iostream>

#define LOG(msg) std::cout << msg << std::endl


class Base
{
public:
	Base()
	{
		LOG("Base constructed");
	}
	virtual ~Base()
	{
		LOG("Base destrcuted");
	}
};


class Derived : public Base
{
public:
	Derived()
	{
		LOG("Derived constructed");
	}
	~Derived()
	{
		LOG("Derived destrcuted");
	}
};


int main()
{
	Base* base = new Base();
	delete base;
	LOG("-----------------");
	Derived* derived = new Derived();
	delete derived;
	LOG("-----------------");

	// creating instance of Derived but assigning it to a variable of type Base pointer
	Base* poly = new Derived();
	delete poly;
	// -> Derived destructor wouldn't get called <- if Base constructor not virtual -> memory leaks
	

	std::cin.get();
}

/*
 * important for polymorphism
 * virtual destructors don't get overridden but on can be added
 *
 * always necessary if class is permitted to be subclassed
 */
