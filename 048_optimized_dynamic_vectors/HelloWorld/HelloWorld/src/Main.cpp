#include <iostream>
#include <string>
#include <memory>
#include <vector>

#include <stdlib.h>

#define LOG(msg) std::cout << msg <<std::endl


struct Vertex
{
public:
	float x, y, z;
public:
	Vertex(float x, float y, float z)
		: x(x), y(y), z(z) {}

	Vertex(const Vertex& v)
		: x(v.x), y(v.y), z(v.y)
	{
		LOG("copy");
	}
};


int main()
{
	std::vector<Vertex> vertices;
	// reserving memory for three vertices
	vertices.reserve(3);

	// directly save in the vectors memory
	vertices.emplace_back(1, 2, 3);
	vertices.emplace_back(2, 3, 4);
	vertices.emplace_back(3, 4, 5);

	std::cin.get();
}
