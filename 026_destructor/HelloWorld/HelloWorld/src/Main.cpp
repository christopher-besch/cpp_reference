#include <iostream>

#define LOG(msg) std::cout << msg <<std::endl


class Entity
{
public:
	float X, Y;

	// constructor = special method method
	// gets called by creation
	Entity()
	{
		X = 0.0f;
		Y = 0.0f;
		LOG("Created Entity!");
	}

	// destructor
	// gets called by destruction of instance
	~Entity()
	{
		LOG("DESTROYED Entity!");
	}

	// constructors can be overloaded
	Entity(float x, float y)
	{
		X = x;
		Y = y;
		LOG("Created Entity!");
	}

	void Print()
	{
		std::cout << X << ", " << Y << std::endl;
	}
};


void Function()
{
	Entity e(10.0f, 5.0f);
	e.Print();
}


int main()
{
	
	Function();
	std::cin.get();
}

/*
make the constructor private -> can't create instance of class
or:
Log() = delete;
*/