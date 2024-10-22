#include "mutantstack.tpp"

int main() {
    // Crear un MutantStack de enteros
    MutantStack<int> mstack;
    
    mstack.push(10);
    mstack.push(20);
    mstack.push(30);
    mstack.push(40);

    std::cout << "Elementos del MutantStack (usando iteradores):" << std::endl;
    
    // Iterar sobre los elementos del stack
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
        std::cout << *it << std::endl;
    }

    std::cout << "Elementos del MutantStack (usando iteradores inversos):" << std::endl;

    // Iterar en reversa
    for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit) {
        std::cout << *rit << std::endl;
    }

    return 0;
}
