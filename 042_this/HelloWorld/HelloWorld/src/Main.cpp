#include <iostream>
#include <string>

#include <stdlib.h>

#define LOG(msg) std::cout << msg <<std::endl


class Entity
{
private:
	int x, y;
public:
	// this would work fine
	// Entity(int x, int y)
	// 	: x(x), y(y) {}

	Entity(int x, int y)
	{
		Entity* const e = this;
		// can't be done
		// this = nullptr;

		// doesn't do anything
		x = x;
		y = y;

		this->x = x;
		// same as
		// (*this).x = x;
		this->y = y;
	}

	int GetX() const
	{
		// because method is const ->
		const Entity* const e = this;

		return this->x;
	}
};


int main()
{
	

	std::cin.get();
}

/*
 *this can only be used from within a non-static method (=member function)
 *this represents the current instance used in (=const pointer to it -> object pointed to can't be exchanged but can be changed)
 *when this is used in a const method, this is const in two ways -> same as before + can't change object pointed to
 *
 *delete this; // should not be used
 */
