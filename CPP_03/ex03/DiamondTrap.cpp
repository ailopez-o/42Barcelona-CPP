#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"), FragTrap(), ScavTrap() {
    this->name = "Default";
    std::cout << "DiamondTrap " << this->name << " constructed (default)." << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name) {
    this->name = name;
    this->hitPoints = FragTrap::hitPoints;  // Usar hitPoints de FragTrap
    this->energyPoints = ScavTrap::energyPoints;  // Usar energyPoints de ScavTrap
    this->attackDamage = FragTrap::attackDamage;  // Usar attackDamage de FragTrap
    std::cout << "DiamondTrap " << this->name << " constructed." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other.ClapTrap::name) FragTrap(other), ScavTrap(other) {
    this->name = other.name;
    std::cout << "DiamondTrap " << this->name << " copy constructed." << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
    FragTrap::operator=(other);
    ScavTrap::operator=(other);
    this->name = other.name;
    std::cout << "DiamondTrap " << this->name << " copy assigned." << std::endl;
    return *this;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap " << this->name << " destructed." << std::endl;
}

void DiamondTrap::attack(const std::string& target) {
    ScavTrap::attack(target);  // Usar la versión de ataque de ScavTrap
}

void DiamondTrap::whoAmI() {
    std::cout << "DiamondTrap name: " << this->name << ", ClapTrap name: " << ClapTrap::name << std::endl;
}
