#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"

// Definición de uintptr_t para compatibilidad con C++98
#ifndef UINTPTR_MAX
typedef unsigned long uintptr_t;
#endif

class Serializer
{
public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);

private:
    Serializer(); // Constructor privado para evitar instanciación
    Serializer(const Serializer& other); // Constructor de copia privado
    Serializer& operator=(const Serializer& other); // Operador de asignación privado
    ~Serializer(); // Destructor privado
};

#endif // SERIALIZER_HPP
