#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain constructed." << std::endl;
}

Brain::Brain(const Brain& other) {
    *this = other;
    std::cout << "Brain copy constructed." << std::endl;
}

Brain& Brain::operator=(const Brain& other) {
    if (this != &other) {
        for (int i = 0; i < 100; ++i) {
            this->ideas[i] = other.ideas[i];
        }
    }
    std::cout << "Brain assigned." << std::endl;
    return *this;
}

Brain::~Brain() {
    std::cout << "Brain destructed." << std::endl;
}
