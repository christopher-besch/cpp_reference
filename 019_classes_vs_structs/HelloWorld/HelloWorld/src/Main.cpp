#include <iostream>

#define LOG(msg) std::cout << msg <<std::endl


// object
class Player
{
// make following variables public -> can be accessed from outside this class
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


// object
struct Player2
{
	// public by default
	int x, y;
	int speed;

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

structs are for backwards compatibility

Way of using structs:
	 for POD (=plain old data)
	<- structs for a bunch of variables + methods that minipulate those variables
	<- never inheritance with structs
*/
