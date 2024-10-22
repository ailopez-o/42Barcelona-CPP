#include "pmerge.hpp"
#include <iostream>
#include <ctime> // Para medir el tiempo

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Error: no input provided." << std::endl;
        return 1;
    }

    try {
        PmergeMe sorter(argc, argv);

        // Mostrar la secuencia antes de ordenar
        std::cout << "Before: ";
        sorter.printContainer(sorter.getNumbersVector());

        // Medir el tiempo de ejecución para std::vector
        clock_t startVector = clock();
        sorter.sortWithVector();
        clock_t endVector = clock();
        double timeVector = static_cast<double>(endVector - startVector) / CLOCKS_PER_SEC * 1000000;

        // Medir el tiempo de ejecución para std::deque
        clock_t startDeque = clock();
        sorter.sortWithDeque();
        clock_t endDeque = clock();
        double timeDeque = static_cast<double>(endDeque - startDeque) / CLOCKS_PER_SEC * 1000000;

        // Mostrar los resultados y tiempos
        std::cout << "After (vector): ";
        sorter.printContainer(sorter.getNumbersVector());

        std::cout << "After (deque): ";
        sorter.printContainer(sorter.getNumbersDeque());

        std::cout << "Time to process a range of " << sorter.getNumbersVector().size() 
                  << " elements with std::vector: " 
                  << timeVector << " us" << std::endl;

        std::cout << "Time to process a range of " << sorter.getNumbersDeque().size() 
                  << " elements with std::deque: " 
                  << timeDeque << " us" << std::endl;

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
