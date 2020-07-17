#include <iostream>
#include <array>

#define LOG(msg) std::cout << msg << std::endl


template<typename T, size_t S>
class Array
{
public:
	// constexpr tells the compiler, it can evaluate this function at compile time
	constexpr size_t size() const
	{
		return S;
	}

	// reference -> elements can be assigned/changed
	T& operator[](size_t index)
	{
		return m_data[index];
	}

	// overload for a const instance
	const T operator[](size_t index) const
	{
		return m_data[index];
	}

	T* data()
	{
		return m_data;
	}

	const T* data() const
	{
		return m_data;
	}
private:
	T m_data[S];
};


int main()
{
	// size has to be defined at compile time
	int array[5];
	// size has to be known at run time
	int* heap_array = new int[5];
	delete[] heap_array;

	std::array<int, 10> collection;
	collection.size();
	collection[0];

	Array<int, 5> data;
	data.size();

	memset(data.data(), 0, data.size() * sizeof(int));
	memset(&data[0], 0, data.size() * sizeof(int));

	// assert this at compile time
	static_assert(data.size() < 10, "Size is pretty large!");
	
	std::cin.get();
}
