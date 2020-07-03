#include <iostream>

#define LOG(msg) std::cout << msg << std::endl


class Base
{
	
};


class Derived : public Base
{
	
};


class AnotherClass : public Base
{
	
};


int main()
{
	int a = 5;
	// implicit conversion
	// double value = a;
	// explicit
	// C cast
	double value = (double)a;

	// C++ cast
	double s =  static_cast<double>(a);

	Derived* derived = new Derived();
	// cast into a Base
	Base* base = derived;
	// see if conversion to Derived is possible <- base is a Derived instance
	Derived* ac = dynamic_cast<Derived*>(derived);
	if (ac == NULL)
	{
		// do stuff if conversion impossible
		LOG("Not a Derived instance");
	} else
	{
		LOG("An Derived instance");
	}

	std::cin.get();
}

/*
 * static_cast			convert from one type to another, perform checks at compile time
 * dynamic_cast			perform checks at run time
 * reinterprete_cast	just reading a variable as another type (type punning)
 * const_cast			add or remove const
 *
 * C and C++ casts in the end do / can do the same
 */
