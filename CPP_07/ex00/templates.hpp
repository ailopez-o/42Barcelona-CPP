#ifndef TEMPLATES_HPP
#define TEMPLATES_HPP

#include <iostream>

// swap: Intercambia los valores de dos argumentos.
template <typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

// min: Devuelve el valor mínimo entre dos argumentos.
template <typename T>
T min(const T& a, const T& b) {
    return (a < b) ? a : b;
}

// max: Devuelve el valor máximo entre dos argumentos.
template <typename T>
T max(const T& a, const T& b) {
    return (a > b) ? a : b;
}

#endif
