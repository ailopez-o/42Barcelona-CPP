#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    std::cout << "ScavTrap " << this->name << " constructed (default)." << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    std::cout << "ScavTrap " << this->name << " constructed." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    std::cout << "ScavTrap " << this->name << " copy constructed." << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    ClapTrap::operator=(other);
    std::cout << "ScavTrap " << this->name << " copy assigned." << std::endl;
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << this->name << " destructed." << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    if (this->energyPoints > 0 && this->hitPoints > 0) {
        std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
        this->energyPoints--;
    } else {
        std::cout << "ScavTrap " << this->name << " cannot attack because it has no energy points or hit points left." << std::endl;
    }
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode." << std::endl;
}
