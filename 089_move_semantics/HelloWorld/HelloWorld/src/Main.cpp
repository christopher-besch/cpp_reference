#include <iostream>
#include <string>
#include <chrono>

#define LOG(msg) std::cout << msg << std::endl


class String
{
private:
	char* m_data;
	uint32_t m_size;
public:
	String() = default;
	
	String(const char* string)
	{
		printf("Created!\n");

		m_size = strlen(string);
		m_data = new char[m_size];
		memcpy(m_data, string, m_size);
	}
	
	String(const String& other)
	{
		printf("Copied!\n");

		m_size = other.m_size;
		m_data = new char[m_size];
		memcpy(m_data, other.m_data, m_size);
	}

	// instead of copying a temporary value, move it
	String(String&& other) noexcept
	{
		printf("Moved!\n");
		
		m_size = other.m_size;
		m_data = other.m_data;
		// no copy

		// stealing others data -> created a hollow object
		other.m_size = 0;
		other.m_data = nullptr; // -> on destruction nullptr gets deleted -> does nothing
	}

	~String()
	{
		printf("Destroyed!\n");
		delete[] m_data;
	}

	void print()
	{
		for (uint32_t i = 0; i < m_size; i++)
			printf("%c", m_data[i]);
		printf("\n");
	}
};


class Entity
{
private:
	String m_name;
public:
	Entity(String& name)
		: m_name(name) {}

	// necessary
	Entity(String&& name)
		: m_name((String&&)name) {}

	void print_name()
	{
		m_name.print();
	}
};


int main()
{
	Entity entity(String("Cherno"));
	entity.print_name();
	
	std::cin.get();
}

/*
 * usually: when a function needs a temporary object, it needs to be created and then copied into the function
 */