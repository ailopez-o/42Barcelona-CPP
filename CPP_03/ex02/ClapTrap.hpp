#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>
#include "ClapTrap.hpp"

class ClapTrap {
protected:
    std::string name;
    unsigned int hitPoints;
    unsigned int energyPoints;
    unsigned int attackDamage;

public:
    ClapTrap(); // Constructor por defecto
    ClapTrap(const std::string& name); // Constructor con parámetros
    ClapTrap(const ClapTrap& other); // Constructor de copia
    ClapTrap& operator=(const ClapTrap& other); // Operador de asignación de copia
    ~ClapTrap(); // Destructor

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif // CLAPTRAP_HPP
