#include "Animal.hpp"

Animal::Animal() : type("") {
    std::cout << "Animal constructed." << std::endl;
}

Animal::Animal(const Animal& other) : type(other.type) {
    std::cout << "Animal copy constructed." << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
    if (this != &other) {
        type = other.type;
    }
    std::cout << "Animal assigned." << std::endl;
    return *this;
}

Animal::~Animal() {
    std::cout << "Animal destructed." << std::endl;
}

void Animal::makeSound() const {
    std::cout << "Animal makes a sound." << std::endl;
}

std::string Animal::getType() const {
    return type;
}
