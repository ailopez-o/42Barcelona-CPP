#include "FixedPointNumber.hpp"
#include <cmath> // Para std::round y otras operaciones matemáticas

// Implementaciones de constructores, destructor y funciones miembro aquí...


FixedPointNumber::FixedPointNumber() : value(0) {
    //std::cout << "Default constructor called" << std::endl;
}

FixedPointNumber::FixedPointNumber(const int integer) : value(integer << fractionalBits) {
    //std::cout << "Int constructor called" << std::endl;
}

FixedPointNumber::FixedPointNumber(const float floatingPoint)
    : value(static_cast<int>(round(floatingPoint * (1 << fractionalBits)))) {
    //std::cout << "Float constructor called" << std::endl;
    }

FixedPointNumber::FixedPointNumber(const FixedPointNumber& other) {
    //std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

FixedPointNumber& FixedPointNumber::operator=(const FixedPointNumber& other) {
    //std::cout << "Copy assignment operator called" << std::endl;

    if (this != &other) {
        this->value = other.value;
    }
    return *this;
}

FixedPointNumber::~FixedPointNumber() {
    //std::cout << "Destructor called" << std::endl;
}

int FixedPointNumber::getRawBits(void) const {
    //std::cout << "getRawBits member function called" << std::endl;
    return this->value;
}

void FixedPointNumber::setRawBits(int const raw) {
    //std::cout << "getRawBits member function called" << std::endl;
    this->value = raw;
}

float FixedPointNumber::toFloat(void) const {
    return static_cast<float>(this->value) / (1 << fractionalBits);
}

int FixedPointNumber::toInt(void) const {
    return this->value >> fractionalBits;
}


// Operadores de comparación
bool FixedPointNumber::operator>(const FixedPointNumber& rhs) const {
    return this->value > rhs.value;
}

bool FixedPointNumber::operator<(const FixedPointNumber& rhs) const {
    return this->value < rhs.value;
}

bool FixedPointNumber::operator>=(const FixedPointNumber& rhs) const {
    return this->value >= rhs.value;
}

bool FixedPointNumber::operator<=(const FixedPointNumber& rhs) const {
    return this->value <= rhs.value;
}

bool FixedPointNumber::operator==(const FixedPointNumber& rhs) const {
    return this->value == rhs.value;
}

bool FixedPointNumber::operator!=(const FixedPointNumber& rhs) const {
    return this->value != rhs.value;
}

// Operadores aritméticos
FixedPointNumber FixedPointNumber::operator+(const FixedPointNumber& rhs) const {
    return FixedPointNumber(this->toFloat() + rhs.toFloat());
}

FixedPointNumber FixedPointNumber::operator-(const FixedPointNumber& rhs) const {
    return FixedPointNumber(this->toFloat() - rhs.toFloat());
}

FixedPointNumber FixedPointNumber::operator*(const FixedPointNumber& rhs) const {
    return FixedPointNumber(this->toFloat() * rhs.toFloat());
}

FixedPointNumber FixedPointNumber::operator/(const FixedPointNumber& rhs) const {
    return FixedPointNumber(this->toFloat() / rhs.toFloat());
}

// Pre-incremento
FixedPointNumber& FixedPointNumber::operator++() {
    this->value += 1; // Incrementa el valor mínimo representable, que es 1 en la representación de punto fijo
    return *this;
}

// Post-incremento
FixedPointNumber FixedPointNumber::operator++(int) {
    FixedPointNumber temp = *this; // Copia el estado actual
    ++(*this); // Utiliza el operador de pre-incremento
    return temp; // Devuelve el estado antes del incremento
}

// Pre-decremento
FixedPointNumber& FixedPointNumber::operator--() {
    this->value -= 1; // Decrementa el valor mínimo representable
    return *this;
}

// Post-decremento
FixedPointNumber FixedPointNumber::operator--(int) {
    FixedPointNumber temp = *this; // Copia el estado actual
    --(*this); // Utiliza el operador de pre-decremento
    return temp; // Devuelve el estado antes del decremento
}

// Retorna una referencia al menor de dos números de punto fijo
FixedPointNumber& FixedPointNumber::min(FixedPointNumber& a, FixedPointNumber& b) {
    return (a < b) ? a : b;
}

// Versión const de min
const FixedPointNumber& FixedPointNumber::min(const FixedPointNumber& a, const FixedPointNumber& b) {
    return (a < b) ? a : b;
}

// Retorna una referencia al mayor de dos números de punto fijo
FixedPointNumber& FixedPointNumber::max(FixedPointNumber& a, FixedPointNumber& b) {
    return (a > b) ? a : b;
}

// Versión const de max
const FixedPointNumber& FixedPointNumber::max(const FixedPointNumber& a, const FixedPointNumber& b) {
    return (a > b) ? a : b;
}

std::ostream& operator<<(std::ostream& out, const FixedPointNumber& fpn) {
    out << fpn.toFloat(); // Utiliza toFloat() para convertir a float antes de imprimir
    return out;
}


