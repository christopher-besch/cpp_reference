#include <iostream>

#define LOG(msg) std::cout << msg <<std::endl


class Entity
{
public:
	// declare as virtual -> allows 
	virtual std::string GetName()
	{
		return "Entity";
	}
};



class Player : public Entity
{
private:
	std::string m_Name;
public:
	
	Player(const std::string& name) : m_Name(name)
	{
		
	}
	//                    <-nice to use, not necessary
	std::string GetName() override {
		return m_Name;
	}
};


void PrintName(Entity* entity)
{
	LOG(entity->GetName());
}


int main()
{
	Entity* e = new Entity();
	LOG(e->GetName());
	PrintName(e);
	Player* p = new Player("Cherno");
	LOG(p->GetName());
	PrintName(p);

	// pointer test
	Player p_copy = *p;
	LOG(p_copy.GetName());

	std::cin.get();
}

/*
 * virtual methods allow derived classes to override those methods
 */
