#include "Zombie.hpp"


Zombie::~Zombie() 
{  
        std::cout << name << " is destroyed." << std::endl;
}

void Zombie::Announce(void) 
{
        std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string newName) 
{
        name = newName; // Setter for the name, in case we use the default constructor
}