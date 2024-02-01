#include "HumanB.hpp"
#include "Weapon.hpp"

void HumanB::attack() const 
{
	if (weapon) {
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
	} else {
		std::cout << name << " has no weapon to attack with" << std::endl;
	}
}


void HumanB::setWeapon(Weapon& newWeapon) 
{
	weapon = &newWeapon;
}