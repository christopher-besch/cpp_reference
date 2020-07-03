#include <iostream>


class Entity
{
public:
	// only belong to class, not instance
	static int x, y;

	static void Print()
	{
		std::cout << x << ", " << y << std::endl;
	}
};

int Entity::x;
int Entity::y;

int main()
{
	Entity e;
	e.x = 2;
	e.y = 3;

	// Entity e1 = {5, 8};
	Entity e1;
	e1.x = 5;
	Entity::y = 8;

	e.Print();
	Entity::Print();

	std::cin.get();
}

/*
static variable in class -> only one instance of that variable over all instances of the class
static method can't access non static variables
<- static methods don't belong to an instance
*/
