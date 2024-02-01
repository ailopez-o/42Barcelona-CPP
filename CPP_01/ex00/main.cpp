#include <iostream>
#include <string>
#include "Zombie.hpp"


Zombie* newZombie(std::string name) 
{
    return new Zombie(name);  // Dynamically allocate a new Zombie object on the heap
}

void randomChump(std::string name) 
{
    Zombie zombie(name);  // Create a Zombie object on the stack
    zombie.Announce();    // The zombie announces itself
}

int main() {
    // Using newZombie function to create a zombie on the heap
    Zombie* heapZombie = newZombie("HeapZombie");
    heapZombie->Announce();
    delete heapZombie;  // It's crucial to delete heap-allocated zombies to avoid memory leaks

    // Using randomChump function to create a zombie on the stack
    randomChump("StackZombie");
    return 0;
}