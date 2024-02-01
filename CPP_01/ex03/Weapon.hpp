#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class Weapon {
private:
    std::string type;

public:

    Weapon(std::string type) : type(type) {}
    const std::string& getType() const;
    void setType(const std::string& newType);
};

#endif