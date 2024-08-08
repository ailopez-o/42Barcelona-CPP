#include "Identify.hpp"

// Función para generar instancias aleatorias de A, B o C
Base* generate()
{
    std::srand(std::time(0));
    int randNum = std::rand() % 3;
    if (randNum == 0)
        return new A();
    else if (randNum == 1)
        return new B();
    else
        return new C();
}

// Identificar el tipo a través de puntero
void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

// Identificar el tipo a través de referencia
void identify(Base& p)
{
    Base* ptr = &p;

    if (dynamic_cast<A*>(ptr))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(ptr))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(ptr))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}
