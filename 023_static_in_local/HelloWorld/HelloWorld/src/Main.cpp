#include <iostream>

#define LOG(msg) std::cout << msg <<std::endl


class Singleton
{
public:
	static Singleton& Get()
	{
		// only one instance exists ever <- static
		static Singleton instance;
		return instance;
	}

	void Hello()
	{

	}
};



void Function()
{
	// can only be accessed from this function
	// and always stays <- as if it where declared in global scope
	static int i = 0;
	i++;
	LOG(i);
}


int main()
{
	Singleton::Get().Hello();
	
	Function();
	Function();
	Function();
	Function();
	std::cin.get();
}

/*
lifetime of a variable:
	for how long will the variable stay in memory
scope of a variable:
	where the variable can be accessed
*/
