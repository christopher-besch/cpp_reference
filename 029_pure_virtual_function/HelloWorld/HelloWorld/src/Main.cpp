#include <iostream>

#define LOG(msg) std::cout << msg <<std::endl


class Printable
{
public:
	// declare pure virtual function-> template only
	// = interface
	virtual std::string GetName() = 0;
};


class Entity : public Printable
{
public:
	std::string GetName() override {
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


void PrintName(Printable* obj)
{
	LOG(obj->GetName());
}


int main()
{
	Entity* e = new Entity();
	LOG(e->GetName());
	PrintName(e);

	Player* p = new Player("Cherno");
	LOG(p->GetName());
	PrintName(p);

	std::cin.get();
}

/*
 * pure virtual don't have a function definition but force derived functions to make one
 */
