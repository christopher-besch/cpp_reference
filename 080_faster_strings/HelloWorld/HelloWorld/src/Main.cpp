#include <iostream>
#include <string>

#define LOG(msg) std::cout << msg << std::endl

static uint32_t s_alloc_count = 0;


void* operator new(size_t size)
{
	s_alloc_count++;
	LOG("allocating " << size << " bytes");

	return malloc(size);
}


void print_str(const std::string& str)
{
	LOG(str);
}


int main()
{
	std::string name = "Cherno Test";
	print_str(name);

	print_str("Cherno Test");

	std::string first_name = name.substr(0, 6);
	print_str(first_name);

	//                                    <- gives const char*
	//                                              <- offset
	std::string_view first_name2(name.c_str() + 0, 6);
	LOG(first_name2);

	const char* name2 = "Cherno Test";
	LOG(name2);
	std::string_view first_name3(name2 + 0, 6);
	LOG(first_name3);

	LOG("allocations: " << s_alloc_count);
	std::cin.get();
}

/*
 * std::string always allocates on the heap (actually only most of the time) -> overhead
 * 
 * std::string_view doesn't allocate memory on the heap -> less overhead
 * it allows a substring of an already existing string to be accessed
 * can easily be used by value rather than by reference
 *
 * functions can just take a std::string_view instead of a std::string -> no heap allocation
 */
