#include <iostream>
#include <vector>
#include <list>
#include <algorithm> // Para std::find
#include <stdexcept> // Para std::exception

// Plantilla de función easyfind
template <typename T>
typename T::iterator easyfind(T& container, int value) {
    // Usamos std::find para buscar la primera ocurrencia
    typename T::iterator it = std::find(container.begin(), container.end(), value);

    // Si no encontramos el valor, lanzamos una excepción
    if (it == container.end()) {
        throw std::runtime_error("Value not found in container");
    }

    // Devolvemos el iterador si encontramos el valor
    return it;
}

