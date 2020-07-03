#include <iostream>

#define LOG(msg) std::cout << msg << std::endl


class Entity
{
public:
	virtual void print_name()
	{
		
	}
};


class Player : public Entity
{
	
};


class Enemy : public Entity
{
	
};


int main()
{
	// player has both Player and Entity associated with it
	Player* player = new Player();
	// possible
	Entity* e = player;
	// impossible <- could have been an Enemy
	// Player* p = e;
	// reassuring compiler that you you know what you're doing -> might cause problems if you actually don't
	// C style cast
	Player* p = (Player*)e;
	// same as C++ cast
	// Player* p = static_cast<Player*>(e);

	Enemy* e1 = new Enemy();
	// dynamic cast -> Enemy needs to be polymorphic class type
	Player* p1 = dynamic_cast<Player*>(e); // -> nullptr
	

	std::cin.get();
}

/*
 * dynamic cast is evaluated at runtime -> overhead
 * runtime type information (RTTTI) is stored -> overhead
 *
 * RTTTI can be turned off under project properties -> C/C++ -> Language
 */
