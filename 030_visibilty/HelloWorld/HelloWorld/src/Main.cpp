#include <iostream>

#define LOG(msg) std::cout << msg <<std::endl


class entity
{
// nothing but this object and its friends can access these variables and functions
private:
	int x = 0;
	
// nothing but this object and its friends can access these variables and functions and from this inheriting objects
protected:
	int y = 0;

// everyone can access these variables and functions
public:
	int z = 0;
};


int main()
{

	std::cin.get();
}
