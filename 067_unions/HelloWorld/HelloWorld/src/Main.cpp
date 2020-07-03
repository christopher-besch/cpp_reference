#include <iostream>

#define LOG(msg) std::cout << msg << std::endl


class Entity
{
public:
	int x, y;
};


struct Vector2
{
	float x, y;
};


struct Vector3
{
	// both structs occupy the same bit of memory
	union
	{
		struct
		{
			float x, y, z, w;
		};
		struct
		{
			Vector2 a, b;
		};
	};
	
};


int main()
{
	class Union
	{
	public:
		// anonymous
		union
		{
			float a;
			int b;
		};
	};

	Union u;
	u.a = 2.0f;
	LOG(u.a);
	// data of a represented as an int
	LOG(u.b);

	Vector3 v = { 1.00f, 2.00f, 3.00f, 4.00f };
	LOG(v.y);
	LOG(v.a.y);

	std::cin.get();
}

/*
 * unions are a class type
 * but can only occupy the memory of one member at any time
 * often used anonymously
 */
