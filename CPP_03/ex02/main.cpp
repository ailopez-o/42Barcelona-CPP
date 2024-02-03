#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main() {
    ClapTrap clap("CL4P-TP");
    FragTrap frag("FR4G-TP");

    std::cout << "\n--- ClapTrap Actions ---\n";
    clap.attack("un enemigo");

    std::cout << "\n--- FragTrap Actions ---\n";
    frag.attack("un tercer enemigo");
    frag.highFivesGuys();

    return 0;
}
