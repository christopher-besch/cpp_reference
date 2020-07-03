#include <iostream>
#include <string>
#include <memory>

#include <stdlib.h>

#define LOG(msg) std::cout << msg <<std::endl


class Entity
{
public:
	Entity()
	{
		LOG("Created Entity!");
	}

	~Entity()
	{
		LOG("Destroyed Entity!");
	}
};


int main()
{
	{
		std::shared_ptr<Entity> e0;
		{
			////////////////////
			// unique pointer //
			////////////////////

			// std::unique_ptr<Entity> entity(new Entity());
			// same as
			// std::unique_ptr<Entity> entity = std::unique_ptr<Entity>(new Entity());
			// but this is preferred
			std::unique_ptr<Entity> entity = std::make_unique<Entity>();

			// impossible
			// std::unique_ptr<Entity> e0 = entity;

			////////////////////
			// shared pointer //
			////////////////////

			// has to use this way <- control block necessary
			std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();
			e0 = sharedEntity;

			//////////////////
			// weak pointer //
			//////////////////

			// same as "normal" copy without raising the reference counter
			std::weak_ptr<Entity> weakEntity = sharedEntity;
		}
	}

	std::cin.get();
}


/*
 * smart pointers are a wrapper around "real" raw pointers
 * should always be used
 *
 * unique pointers:
 *	must be unique
 *	<- unique pointers free the memory pointing to upon death -> any copy of the unique pointer now points to garbage
 * shared pointer:
 *	using reference counting (how many references are still left)
 */
