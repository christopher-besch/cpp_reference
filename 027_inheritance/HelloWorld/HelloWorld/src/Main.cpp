#include <iostream>

#define LOG(msg) std::cout << msg <<std::endl


class Entity
{
public:
	float X, Y;

	void Move(float xa, float ya)
	{
		X += xa;
		Y += ya;
	}
};


// inherit from Entity class
class Player : public Entity
{
public:
	const char* Name;
	
	void PrintName()
	{
		LOG(Name);
	}
};


int main()
{
	Player player;

	player.Move(5, 4);
	LOG(player.X);
	LOG(player.Y);

	std::cin.get();
}
