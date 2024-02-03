#ifndef FIXEDPOINTNUMBER_HPP
#define FIXEDPOINTNUMBER_HPP

#include <iostream>

class FixedPointNumber {
private:
    int value;
    static const int fractionalBits = 8;

public:
    // Constructores y destructor
    FixedPointNumber();
    FixedPointNumber(const int integer);
    FixedPointNumber(const float floatingPoint);
    FixedPointNumber(const FixedPointNumber& other);
    FixedPointNumber& operator=(const FixedPointNumber& other);
    ~FixedPointNumber();

    // Funciones miembro
    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;

    // Operadores de comparación
    bool operator>(const FixedPointNumber& rhs) const;
    bool operator<(const FixedPointNumber& rhs) const;
    bool operator>=(const FixedPointNumber& rhs) const;
    bool operator<=(const FixedPointNumber& rhs) const;
    bool operator==(const FixedPointNumber& rhs) const;
    bool operator!=(const FixedPointNumber& rhs) const;

    // Operadores aritméticos
    FixedPointNumber operator+(const FixedPointNumber& rhs) const;
    FixedPointNumber operator-(const FixedPointNumber& rhs) const;
    FixedPointNumber operator*(const FixedPointNumber& rhs) const;
    FixedPointNumber operator/(const FixedPointNumber& rhs) const;

    // Operadores de incremento/decremento
    FixedPointNumber& operator++(); // Pre-incremento
    FixedPointNumber operator++(int); // Post-incremento
    FixedPointNumber& operator--(); // Pre-decremento
    FixedPointNumber operator--(int); // Post-decremento

    // Funciones estáticas min/max
    static FixedPointNumber& min(FixedPointNumber& a, FixedPointNumber& b);
    static const FixedPointNumber& min(const FixedPointNumber& a, const FixedPointNumber& b);
    static FixedPointNumber& max(FixedPointNumber& a, FixedPointNumber& b);
    static const FixedPointNumber& max(const FixedPointNumber& a, const FixedPointNumber& b);

    // Sobrecarga del operador de inserción
    friend std::ostream& operator<<(std::ostream& out, const FixedPointNumber& fpn);
};

#endif // FIXEDPOINTNUMBER_HPP
