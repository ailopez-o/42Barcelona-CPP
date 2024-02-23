#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"


int main() {
    Animal* animal = new Animal();
    Animal* dog = new Dog();
    Animal* cat = new Cat();

    std::cout << dog->getType() << " " << std::endl;
    std::cout << cat->getType() << " " << std::endl;
    std::cout << animal->getType() << " " << std::endl;

	animal->makeSound();
    dog->makeSound(); 
	cat->makeSound();
}
