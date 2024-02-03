#include "ClapTrap.hpp"

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Default"), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap " << this->name << " has been constructed (default)." << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap " << this->name << " has been constructed." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : name(other.name), hitPoints(other.hitPoints), energyPoints(other.energyPoints), attackDamage(other.attackDamage) {
    std::cout << "ClapTrap " << this->name << " has been copy constructed." << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    std::cout << "ClapTrap " << this->name << " is being copy assigned." << std::endl;
    if (this != &other) {
        this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << this->name << " has been destroyed." << std::endl;
}

void ClapTrap::attack(const std::string& target) {
    if (this->energyPoints > 0 && this->hitPoints > 0) {
        std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
        this->energyPoints--; // Disminuir los puntos de energía después de atacar
    } else {
        std::cout << "ClapTrap " << this->name << " cannot attack because it has no energy points or hit points left." << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (this->hitPoints > amount) {
        this->hitPoints -= amount; // Disminuir los puntos de vida en la cantidad de daño recibido
        std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage!" << std::endl;
    } else {
        this->hitPoints = 0; // Asegurar que los puntos de vida no sean negativos
        std::cout << "ClapTrap " << this->name << " is destroyed!" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->energyPoints > 0 && this->hitPoints > 0) {
        this->hitPoints += amount; // Aumentar los puntos de vida
        this->energyPoints--; // Disminuir los puntos de energía después de reparar
        std::cout << "ClapTrap " << this->name << " repairs itself, recovering " << amount << " hit points." << std::endl;
    } else {
        std::cout << "ClapTrap " << this->name << " cannot repair itself because it has no energy points left or it's already destroyed." << std::endl;
    }
}

