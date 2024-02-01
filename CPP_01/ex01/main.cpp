#include <iostream>
#include <string>
#include "Zombie.hpp"
#include "Zombie.h"


int main() {
    int N = 5; // Number of zombies in the horde
    std::string name = "HordeZombie";

    // Create a horde of zombies
    Zombie* horde = zombieHorde(N, name);

    // Announce each zombie in the horde
    for (int i = 0; i < N; ++i) {
        horde[i].Announce();
    }

    // Clean up the horde to avoid memory leaks
    delete[] horde;

    return 0;
}