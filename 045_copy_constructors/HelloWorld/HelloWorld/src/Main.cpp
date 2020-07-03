#include <iostream>
#include <string>
#include <memory>

#include <stdlib.h>

#define LOG(msg) std::cout << msg <<std::endl


class String
{
private:
	char* m_Buffer;
	unsigned int m_Size;
public:
	explicit String(const char* string)
	{
		// strcpy() could have been used here <- includes null termination character

		m_Size = strlen(string);
		m_Buffer = new char[m_Size + 1];
		// fill everything except for the last entry with the string
		// destination address, origin address, size
		memcpy(m_Buffer, string, m_Size);
		// add null termination character
		m_Buffer[m_Size] = 0;
	}

	//////////////////////
	// copy constructor //
	//////////////////////
	
	// can't be explicit
	
	// would be the same as the normal shallow copy
	// String(const String& other)
	//	: m_Buffer(other.m_Buffer), m_Size(other.m_Size) {}
	
	// or
	// String(const String other)
	// {
	// 	memcpy(this, &other, sizeof(String));
	// }

	// this would disable the ability to copy an instance of this class
	// String(const String& other) = delete;

	// deep copy
	String(const String& other)
		: m_Size(other.m_Size)
	{
		m_Buffer = new char[m_Size + 1];
		// as it is known that String always has a null termination character, it can just be copied and doesn't have do added manually
		memcpy(m_Buffer, other.m_Buffer, m_Size + 1);
	}

	~String()
	{
		delete[] m_Buffer;
	}

	char& operator[](unsigned int index)
	{
		// NO SAFETY CHECKS
		return m_Buffer[index];
	}

	// allowing this function to access private variables
	friend std::ostream& operator<<(std::ostream& stream, const String& string);
};


std::ostream& operator<<(std::ostream& stream, const String& string)
{
	stream << string.m_Buffer;
	return stream;
}


void Test(int x)
{
	
}
// array with parameters
int parameters[1];
// means:
int x = parameters[0];


int main()
{
	int a = 2;
	// creating a copy of a
	int b = a;

	int* c = &a;
	// creating a copy of the pointer, not of the object pointed to
	int* d = c;

	LOG(*c); // 2
	(*d)++;
	LOG(*c); // 3

	
	String string = String("Cherno");
	
	// String second = string;
	// same as
	String second = String(string);

	second[2] = 'a';
	
	std::cout << string << std::endl;
	std::cout << second << std::endl;

	std::cin.get();
}


/*
 * deep copies copy an object in its entirety
 *
 * shallow copy of String instance causes crash <- memory address for m_Buffer is the same -> tying to destroy buffer twice
 *
 * always pass objects by const reference
 */
