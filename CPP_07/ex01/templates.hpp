#ifndef TEMPLATES_HPP
#define TEMPLATES_HPP

#include <iostream>

// Plantilla de función iter: aplica una función a cada elemento de un array.
template <typename T, typename F>
void iter(T* array, size_t length, F func) {
    for (size_t i = 0; i < length; ++i) {
        func(array[i]);
    }
}

// Función que imprime un valor
template <typename T>
void printElement(const T& element) {
    std::cout << element << " ";
}

// Función que incrementa un valor
template <typename T>
void incrementElement(T& element) {
    ++element;
}

#endif
