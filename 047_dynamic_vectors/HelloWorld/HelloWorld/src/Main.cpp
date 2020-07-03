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
};


std::ostream& operator<<(std::ostream& stream, const Vertex& vertex)
{
	stream << vertex.x << ", " << vertex.y << ", " << vertex.z;
	return stream;
}


int main()
{
	std::vector<Vertex> vertices;
	vertices.push_back({ 1, 2, 3 });
	vertices.push_back({ 2, 3, 4 });

	for (int idx = 0; idx < vertices.size(); idx++)
	{
		std::cout << vertices[idx] << std::endl;
	}
	// same as

	for (const Vertex& v : vertices)
	{
		std::cout << v << std::endl;
	}

	// erase specific element
	//                                      <- index
	vertices.erase(vertices.begin() + 1);

	// set array size back to 0
	vertices.clear();
	
	std::cin.get();
}


/*
 * 
 */
