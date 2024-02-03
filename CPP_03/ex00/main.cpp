#include "ClapTrap.hpp"
#include "ClapTrap.hpp"

int main() {
    // Usar el constructor por defecto
    ClapTrap defaultTrap;
    
    // Crear instancias de ClapTrap con nombres
    ClapTrap clapTrap1("CL4P-TP");
    ClapTrap clapTrap2("FR4G-TP");

    // Usar el constructor de copia
    ClapTrap copyTrap(clapTrap1);

    // Usar el operador de asignación de copia
    defaultTrap = clapTrap2;

    // Pruebas de funcionalidades
    clapTrap1.attack("FR4G-TP");
    clapTrap2.takeDamage(3);
    clapTrap2.beRepaired(5);

    return 0;
}
