#include <iostream>

#define LOG(msg) std::cout << msg <<std::endl


// function (and overloads) get created when called (but at compile time)
template<typename T>
static void Print(T msg)
{
	LOG(msg);
}

template<typename T, int N>
class Array
{
private:
	// N needs to be known at compile time
	T m_Array[N];
public:
	int GetSize()
	{
		return N;
	}
};

int main()
{
	// implicit
	Print(5);
	// explicit
	Print<int>(5);
	Print("Hello World!");

	Array<int, 16> array;
	LOG(array.GetSize());

	std::cin.get();
}
