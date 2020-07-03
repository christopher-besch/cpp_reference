#include <iostream>
#include <string>
#include <chrono>

#define LOG(msg) std::cout << msg << std::endl


struct AllocateMetrics
{
	uint32_t total_allocated = 0;
	uint32_t total_freed = 0;

	uint32_t current_usage()
	{
		return total_allocated - total_freed;
	}
};


static AllocateMetrics s_AllocateMetrics;


static void print_memory_usage()
{
	LOG("memory usage: " << s_AllocateMetrics.current_usage() << " bytes");
}


void* operator new(size_t size)
{
	// a breakpoint could go here
	LOG("allocating " << size << " bytes");

	s_AllocateMetrics.total_allocated += size;
	
	return malloc(size);
}


void operator delete(void* memory, size_t size)
{
	LOG("freeing " << size << " bytes");

	s_AllocateMetrics.total_freed += size;
	
	free(memory);
}


struct Object
{
	int x, y, z;
};


int main()
{
	print_memory_usage();
	
	Object* obj = new Object;

	print_memory_usage();

	delete obj;

	print_memory_usage();
	
	std::cin.get();
}
