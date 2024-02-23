#include "Cat.hpp"

Cat::Cat() : brain(new Brain()) {
    std::cout << "Cat constructed." << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
    brain = new Brain(*other.brain); // Copia profunda del Brain
    std::cout << "Cat copy constructed." << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    if (this != &other) {
        Animal::operator=(other);
        delete brain; // Eliminar el Brain actual
        brain = new Brain(*other.brain); // Crear una nueva copia profunda
    }
    std::cout << "Cat assigned." << std::endl;
    return *this;
}

Cat::~Cat() {
    delete brain; // Asegurarse de eliminar el Brain en el destructor
    std::cout << "Cat destructed." << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Meow!" << std::endl;
}
