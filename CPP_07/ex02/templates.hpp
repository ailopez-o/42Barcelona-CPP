#ifndef TEMPLATES_HPP
#define TEMPLATES_HPP

#include <iostream>
#include <stdexcept>  // Para lanzar excepciones


template <typename T>
class Array {
private:
    T* elements;      // Puntero a los elementos del array
    unsigned int n;   // Número de elementos en el array

public:
    // Constructor sin parámetros: crea un array vacío
    Array() : elements(NULL), n(0) {}

    // Constructor con un tamaño 'n' como parámetro
    Array(unsigned int n) : elements(new T[n]()), n(n) {}

    // Constructor por copia
    Array(const Array& other) : elements(NULL), n(0) {
        *this = other;  // Usamos el operador de asignación
    }

    // Operador de asignación
    Array& operator=(const Array& other) {
        if (this != &other) {  // Evitar auto-asignación
            delete[] elements;  // Liberar la memoria actual
            n = other.n;
            if (n > 0) {
                elements = new T[n];  // Asignar nueva memoria
                for (unsigned int i = 0; i < n; ++i) {
                    elements[i] = other.elements[i];  // Copiar elementos
                }
            } else {
                elements = NULL;
            }
        }
        return *this;
    }

    // Destructor: libera la memoria
    ~Array() {
        delete[] elements;
    }

    // Operador de subíndice: permite acceso a los elementos con []
    T& operator[](unsigned int index) {
        if (index >= n) {
            throw std::out_of_range("Index out of bounds");
        }
        return elements[index];
    }

    // Operador de subíndice (constante): permite acceso a los elementos con [] en objetos const
    const T& operator[](unsigned int index) const {
        if (index >= n) {
            throw std::out_of_range("Index out of bounds");
        }
        return elements[index];
    }

    // Función miembro size(): devuelve el tamaño del array
    unsigned int size() const {
        return n;
    }
};

#endif
