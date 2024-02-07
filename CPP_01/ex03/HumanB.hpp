#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanB {
private:
    std::string name;
    Weapon* weapon;  // Puntero a Weapon, permite que HumanB no tenga arma inicialmente

public:
    HumanB(std::string name) : name(name), weapon(NULL) {}
    void setWeapon(Weapon& newWeapon);
    void attack() const;
};

#endif
