#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include <cerrno>
#include <cmath>
#include <cctype>

class ScalarConverter
{
public:
    static void convert(const std::string& literal);

private:
    ScalarConverter(); // Constructor privado para evitar instanciación
    ScalarConverter(const ScalarConverter& other); // Constructor de copia privado
    ScalarConverter& operator=(const ScalarConverter& other); // Operador de asignación privado
    ~ScalarConverter(); // Destructor privado

    static void printChar(double value);
    static void printInt(double value);
    static void printFloat(double value);
    static void printDouble(double value);
};

#endif // SCALARCONVERTER_HPP
