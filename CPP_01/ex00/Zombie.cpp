#include "Zombie.hpp"


Zombie::~Zombie() 
{  
        std::cout << name << " is destroyed." << std::endl;
}

void Zombie::Announce(void) 
{
        std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}