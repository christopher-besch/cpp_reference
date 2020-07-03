#include <iostream>
#include <string>

#include <stdlib.h>

#define LOG(msg) std::cout << msg <<std::endl


class Entity
{
private:
	// the asterisk has to be before each pointer name
	int* m_X, *m_Y;

	// can be accessed by const methods anyways
	mutable int m_Z;
	
public:
	// const in end -> can't access class variables
	int* GetX() const
	{
		// m_X = 2;
		return m_X;
	}

	int* GetY()
	{
		int a = 2;
		// without const class variables can be accessed
		m_Y = &a;
		return m_Y;
	}

	// this function returns an unchangeable pointer pointing towards an unchangeable integer and can't access any class variables
	const int* const Weird() const
	{
		int a = 4;
		const int* const x = &a;
		return x;
	}
};


// eating a const Entity reference
void DoStuff(const Entity& e)
{
	// possible because it promises to not change variables <- has to because e is const
	e.GetX();

	// wouldn't work <- not const
	// e.GetY();
}


int main()
{
	// a non-variable variable
	const int a = 5;

	// const after * -> the content of the pointer can be changed but not the location pointing towards
	int* const b = new int;

	// content at pointer can't be changed
	const int* c = new int;

	*b = 2;
	// b = (int*)&a;
	c = (int*)&a;
	
	LOG(*b);

	std::cin.get();
}

/*
 * const is only a promise and use to make the code be cleaner
 *
 * mark methods as const when possible
 */
