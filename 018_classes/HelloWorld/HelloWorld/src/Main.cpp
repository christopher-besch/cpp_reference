#include <iostream>

#define LOG(msg) std::cout << msg <<std::endl


// object
class Player
{
public:
	int x, y;
	int speed;

	// method
	void Move(int xa, int ya)
	{
		x += xa * speed;
		y += ya * speed;
	}
};


int main()
{
	// instance
	Player player;

	player.x = 5;

	std::cin.get();
}


/*
functions in classes are called methods
*/
