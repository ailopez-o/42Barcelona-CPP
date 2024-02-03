#include "FixedPointNumber.hpp"

// Constructor por defecto
FixedPointNumber::FixedPointNumber() : value(0) {
    std::cout << "Default constructor called" << std::endl;
}

// Constructor de copia
FixedPointNumber::FixedPointNumber(const FixedPointNumber& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

// Operador de asignación de copia
FixedPointNumber& FixedPointNumber::operator=(const FixedPointNumber& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->value = other.value;
    }
    return *this;
}

// Destructor
FixedPointNumber::~FixedPointNumber() {
    std::cout << "Destructor called" << std::endl;
}

// Retorna el valor bruto del número de punto fijo
int FixedPointNumber::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->value;
}

// Establece el valor bruto del número de punto fijo
void FixedPointNumber::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    this->value = raw;
}
