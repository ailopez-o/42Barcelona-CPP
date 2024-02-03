#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    // Creación de un ClapTrap y un ScavTrap
    ClapTrap clap("CL4P-TP");
    ScavTrap scav("SC4V-TP");

    // ClapTrap realiza acciones
    std::cout << "\n--- ClapTrap Actions ---\n";
    clap.attack("un enemigo");
    clap.takeDamage(2);
    clap.beRepaired(5);

    // ScavTrap realiza acciones
    std::cout << "\n--- ScavTrap Actions ---\n";
    scav.attack("otro enemigo");
    scav.takeDamage(15);
    scav.beRepaired(10);
    scav.guardGate();

    // Copia y asignación
    std::cout << "\n--- Copy and Assignment ---\n";
    ScavTrap scavCopy(scav); // Prueba del constructor de copia
    ScavTrap scavAssigned = scavCopy; // Prueba del operador de asignación de copia
    scavAssigned.attack("un enemigo diferente");

    return 0;
}
