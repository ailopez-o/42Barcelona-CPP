#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
private:
    std::string name;  // Nombre único de DiamondTrap

public:
    DiamondTrap();
    DiamondTrap(const std::string& name);
    DiamondTrap(const DiamondTrap& other);
    DiamondTrap& operator=(const DiamondTrap& other);
    ~DiamondTrap();

    void attack(const std::string& target);
    void whoAmI();

    using ScavTrap::energyPoints;
    using FragTrap::hitPoints;
    using FragTrap::attackDamage;
};

#endif // DIAMONDTRAP_HPP
