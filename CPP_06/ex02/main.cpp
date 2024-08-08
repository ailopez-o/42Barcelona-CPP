#include "Identify.hpp"

int main()
{
    Base* ptr = generate();
    identify(ptr);  // Identificar usando puntero
    identify(*ptr); // Identificar usando referencia
    delete ptr;     // Liberar memoria

    return 0;
}
