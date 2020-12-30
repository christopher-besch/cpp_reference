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

class Base {
    public:
        int x;
    protected:
        int y;
    private:
        int z;
};

class PublicDerived: public Base {
    // x is public
    // y is protected
    // z is not accessible from PublicDerived
};

class ProtectedDerived: protected Base {
    // x is protected
    // y is protected
    // z is not accessible from ProtectedDerived
};

class PrivateDerived: private Base {
    // x is private
    // y is private
    // z is not accessible from PrivateDerived
}

int main()
{
	Player player;

	player.Move(5, 4);
	LOG(player.X);
	LOG(player.Y);

	std::cin.get();
}
