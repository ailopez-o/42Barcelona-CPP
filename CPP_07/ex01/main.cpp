#include "templates.hpp"

int main() {
    // Prueba con un array de enteros
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intArrayLength = sizeof(intArray) / sizeof(intArray[0]);

    std::cout << "Array de enteros antes de incrementarlo: ";
    iter(intArray, intArrayLength, printElement<int>);
    std::cout << std::endl;

    // Incrementa cada elemento del array
    iter(intArray, intArrayLength, incrementElement<int>);

    std::cout << "Array de enteros después de incrementarlo: ";
    iter(intArray, intArrayLength, printElement<int>);
    std::cout << std::endl;

    // Prueba con un array de caracteres
    char charArray[] = {'a', 'b', 'c', 'd', 'e'};
    size_t charArrayLength = sizeof(charArray) / sizeof(charArray[0]);

    std::cout << "Array de caracteres: ";
    iter(charArray, charArrayLength, printElement<char>);
    std::cout << std::endl;

    return 0;
}
