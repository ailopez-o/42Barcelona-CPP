#include "HumanA.hpp"
#include "Weapon.hpp"


void HumanA::attack() const 
{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}