#include <iostream>
#include <string>

#include <stdlib.h>

#define LOG(msg) std::cout << msg <<std::endl


struct Vector2
{
public:
	float x, y;

	Vector2(float x, float y)
		: x(x), y(y) {}

	Vector2 operator+(const Vector2& other) const
	{
		return Vector2(x + other.x, y + other.y);
	}

	Vector2 operator*(const Vector2& other) const
	{
		return Vector2(x * other.x, y * other.y);
	}

	bool operator==(const Vector2& other) const
	{
		return x == other.x && y == other.y;
	}

	bool operator!=(const Vector2& other) const
	{
		return !(*this == other);
		// same as
		// return !operator==(other);
	}
};


std::ostream& operator<<(std::ostream& stream, const Vector2& other)
{
	stream << other.x << ", " << other.y;
	return stream;
}


int main()
{
	Vector2 position(4.0f, 4.0f);
	Vector2 speed(0.5f, 1.5f);
	Vector2 powerup(2.0f, 2.0f);

	Vector2 result = position + speed * powerup;

	std::cout << result << std::endl;

	std::cin.get();
}

/*
 *all operators:
 *https://en.cppreference.com/w/cpp/language/operators
 *
 *operators are just functions
 *
 *use of operator overloading should be minimal
 */
