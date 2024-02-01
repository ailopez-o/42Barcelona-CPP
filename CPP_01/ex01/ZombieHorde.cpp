#include <iostream>
#include <string>
#include "Zombie.hpp"


Zombie* zombieHorde(int N, std::string name) 
{
    Zombie* horde = new Zombie[N]; // Allocate an array of N Zombie objects
    for (int i = 0; i < N; ++i) {
        horde[i].setName(name); // Initialize each Zombie's name
    }
    return horde; // Return a pointer to the first Zombie in the array
}