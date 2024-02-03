#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main() {
    DiamondTrap diamond("Diamond");

    std::cout << "\n--- DiamondTrap Actions ---\n";
    diamond.attack("un enemigo");  // Debería usar la versión de ScavTrap
    diamond.takeDamage(30);
    diamond.beRepaired(20);
    diamond.highFivesGuys();  // De FragTrap
    diamond.guardGate();  // De ScavTrap
    diamond.whoAmI();

    return 0;
}
