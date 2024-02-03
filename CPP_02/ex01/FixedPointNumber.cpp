#include "FixedPointNumber.hpp"
#include <cmath> // Para std::round

FixedPointNumber::FixedPointNumber() : value(0) {
    std::cout << "Default constructor called" << std::endl;
}

FixedPointNumber::FixedPointNumber(const int integer) : value(integer << fractionalBits) {
    std::cout << "Int constructor called" << std::endl;

}

FixedPointNumber::FixedPointNumber(const float floatingPoint)
    : value(static_cast<int>(round(floatingPoint * (1 << fractionalBits)))) {
    std::cout << "Float constructor called" << std::endl;

    }

FixedPointNumber::FixedPointNumber(const FixedPointNumber& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

FixedPointNumber& FixedPointNumber::operator=(const FixedPointNumber& other) {
    std::cout << "Copy assignment operator called" << std::endl;

    if (this != &other) {
        this->value = other.value;
    }
    return *this;
}

FixedPointNumber::~FixedPointNumber() {
    std::cout << "Destructor called" << std::endl;

}

int FixedPointNumber::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->value;
}

void FixedPointNumber::setRawBits(int const raw) {
    std::cout << "getRawBits member function called" << std::endl;
    this->value = raw;
}

float FixedPointNumber::toFloat(void) const {
    return static_cast<float>(this->value) / (1 << fractionalBits);
}

int FixedPointNumber::toInt(void) const {
    return this->value >> fractionalBits;
}

std::ostream& operator<<(std::ostream& out, const FixedPointNumber& fpn) {
    out << fpn.toFloat();
    return out;
}
