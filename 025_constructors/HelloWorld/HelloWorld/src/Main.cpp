#include <iostream>

#define LOG(msg) std::cout << msg <<std::endl


class Entity
{
public:
	float X, Y;

	// constructor = special method
	Entity()
	{
		X = 0.0f;
		Y = 0.0f;
	}

	// constructors can be overloaded
	Entity(float x, float y)
	{
		X = x;
		Y = y;
	}

	void Print()
	{
		std::cout << X << ", " << Y << std::endl;
	}
};


int main()
{
	
	Entity e(10.0f, 5.0f);
	e.Print();
	std::cin.get();
}

/*
make the constructor private -> can't create instance of class
or:
Log() = delete;
*/
