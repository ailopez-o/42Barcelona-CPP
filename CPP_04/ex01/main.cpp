#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    const int numAnimals = 10;
    Animal* animals[numAnimals];

    // Llenar la mitad con Dogs y la otra mitad con Cats
    for (int i = 0; i < numAnimals; ++i) {
        if (i < numAnimals / 2) {
            animals[i] = new Dog();
        } else {
            animals[i] = new Cat();
        }
    }

    // Limpieza
    for (int i = 0; i < numAnimals; ++i) {
        delete animals[i];
    }

    return 0;
}
