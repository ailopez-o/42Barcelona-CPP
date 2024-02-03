#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap " << name << " constructed (default)." << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap " << name << " constructed." << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    std::cout << "FragTrap " << name << " copy constructed." << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    ClapTrap::operator=(other);
    std::cout << "FragTrap " << name << " copy assigned." << std::endl;
    return *this;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap " << name << " destructed." << std::endl;
}

void FragTrap::attack(const std::string& target) {
    if (energyPoints > 0 && hitPoints > 0) {
        std::cout << "FragTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
        energyPoints--;
    } else {
        std::cout << "FragTrap " << name << " cannot attack because it has no energy points or hit points left." << std::endl;
    }
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << name << " requests a positive high five!" << std::endl;
}
