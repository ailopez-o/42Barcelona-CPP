#ifndef FIXEDPOINTNUMBER_HPP
#define FIXEDPOINTNUMBER_HPP

#include <iostream>

class FixedPointNumber {
private:
    int value; // Almacena el valor del número de punto fijo
    static const int fractionalBits = 8; // Número de bits fraccionales

public:
    FixedPointNumber(); // Constructor por defecto
    FixedPointNumber(const int integer); // Constructor a partir de un entero
    FixedPointNumber(const float floatingPoint); // Constructor a partir de un flotante
    FixedPointNumber(const FixedPointNumber& other); // Constructor de copia
    FixedPointNumber& operator=(const FixedPointNumber& other); // Operador de asignación de copia
    ~FixedPointNumber(); // Destructor

    int getRawBits(void) const; // Retorna el valor bruto
    void setRawBits(int const raw); // Establece el valor bruto

    float toFloat(void) const; // Convierte a flotante
    int toInt(void) const; // Convierte a entero

    // Sobrecarga del operador de inserción para imprimir el valor
    friend std::ostream& operator<<(std::ostream& out, const FixedPointNumber& fpn);
};

#endif // FIXEDPOINTNUMBER_HPP
