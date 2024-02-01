#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
	private:

	std::string	name;

	public:
	Zombie() {};
	Zombie(std::string name) : name(name) {} 
	~Zombie();
	void Announce(void);
	void setName(std::string newName);
};


#endif