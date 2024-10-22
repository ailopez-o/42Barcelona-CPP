#include "templates.hpp"


int main() {
    try {
        // Crear un array vacío
        Array<int> emptyArray;
        std::cout << "Tamaño del array vacío: " << emptyArray.size() << std::endl;

        // Crear un array con 5 elementos
        Array<int> intArray(5);
        std::cout << "Tamaño del array de enteros: " << intArray.size() << std::endl;

        // Asignar valores a los elementos del array
        for (unsigned int i = 0; i < intArray.size(); ++i) {
            intArray[i] = i * 2;
        }

        // Imprimir los valores del array
        std::cout << "Valores del array de enteros: ";
        for (unsigned int i = 0; i < intArray.size(); ++i) {
            std::cout << intArray[i] << " ";
        }
        std::cout << std::endl;

        // Prueba del constructor por copia
        Array<int> copiedArray = intArray;
        std::cout << "Valores del array copiado: ";
        for (unsigned int i = 0; i < copiedArray.size(); ++i) {
            std::cout << copiedArray[i] << " ";
        }
        std::cout << std::endl;

        // Modificar el array original y verificar que el array copiado no se vea afectado
        intArray[0] = 100;
        std::cout << "Valor modificado en el array original: " << intArray[0] << std::endl;
        std::cout << "Valor del array copiado (debe ser diferente): " << copiedArray[0] << std::endl;

        // Prueba de acceso fuera de rango (debería lanzar una excepción)
        std::cout << "Accediendo a un índice fuera de rango..." << std::endl;
        intArray[10] = 50;  // Esto lanzará una excepción
    } catch (const std::exception& e) {
        std::cerr << "Excepción capturada: " << e.what() << std::endl;
    }

    return 0;
}
