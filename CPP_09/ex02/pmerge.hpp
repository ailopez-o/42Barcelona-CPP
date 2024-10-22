#ifndef PMERGE_HPP
#define PMERGE_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <stdexcept>

class PmergeMe {
public:
    // Constructor que toma los argumentos de la línea de comandos
    PmergeMe(int argc, char* argv[]);

    // Función para procesar la secuencia con std::vector
    void sortWithVector();

    // Función para procesar la secuencia con std::deque
    void sortWithDeque();

    // Getters para acceder a los contenedores
    const std::vector<int>& getNumbersVector() const;
    const std::deque<int>& getNumbersDeque() const;

    // Función auxiliar para imprimir la secuencia
    template<typename Container>
    void printContainer(const Container& container) const {
        for (typename Container::const_iterator it = container.begin(); it != container.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }

private:
    std::vector<int> numbersVector;  // Contenedor con std::vector
    std::deque<int> numbersDeque;    // Contenedor con std::deque

    // Algoritmo Merge-Insertion Sort para std::vector
    void mergeInsertionSortVector(std::vector<int>& arr);

    // Algoritmo Merge-Insertion Sort para std::deque
    void mergeInsertionSortDeque(std::deque<int>& arr);

    // Función auxiliar para dividir y fusionar en std::vector
    void mergeVector(std::vector<int>& arr, const std::vector<int>& left, const std::vector<int>& right);

    // Función auxiliar para dividir y fusionar en std::deque
    void mergeDeque(std::deque<int>& arr, const std::deque<int>& left, const std::deque<int>& right);

    // Función para convertir los argumentos a enteros
    void parseInput(int argc, char* argv[]);
};

#endif
