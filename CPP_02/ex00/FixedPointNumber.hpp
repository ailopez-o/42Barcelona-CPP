#ifndef FIXEDPOINTNUMBER_HPP
#define FIXEDPOINTNUMBER_HPP

#include <iostream>
#include <string>

class FixedPointNumber {
private:
    int value; // Almacena el valor del número de punto fijo
    static const int fractionalBits = 8; // Número de bits fraccionales, siempre 8

public:
    FixedPointNumber(); // Constructor por defecto
    FixedPointNumber(const FixedPointNumber& other); // Constructor de copia
    FixedPointNumber& operator=(const FixedPointNumber& other); // Operador de asignación de copia
    ~FixedPointNumber(); // Destructor

    int getRawBits(void) const; // Retorna el valor bruto del número de punto fijo
    void setRawBits(int const raw); // Establece el valor bruto del número de punto fijo
};

#endif // FIXEDPOINTNUMBER_HPP
