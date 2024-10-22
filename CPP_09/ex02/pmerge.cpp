#include "pmerge.hpp"
#include <sstream>
#include <algorithm>
#include <stdexcept>

// Constructor que toma los argumentos de la línea de comandos
PmergeMe::PmergeMe(int argc, char* argv[]) {
    parseInput(argc, argv);
}

// Función para convertir los argumentos a enteros y llenar los contenedores
void PmergeMe::parseInput(int argc, char* argv[]) {
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        int number;
        std::stringstream ss(arg);

        if (!(ss >> number) || number <= 0) {
            throw std::invalid_argument("Error: invalid input");
        }

        numbersVector.push_back(number);
        numbersDeque.push_back(number);
    }
}

// Función para procesar la secuencia con std::vector
void PmergeMe::sortWithVector() {
    mergeInsertionSortVector(numbersVector);
}

// Función para procesar la secuencia con std::deque
void PmergeMe::sortWithDeque() {
    mergeInsertionSortDeque(numbersDeque);
}

// Algoritmo Merge-Insertion Sort para std::vector
void PmergeMe::mergeInsertionSortVector(std::vector<int>& arr) {
    if (arr.size() <= 1) return;

    // Divide el vector en dos sub-vectores
    int mid = arr.size() / 2;
    std::vector<int> left(arr.begin(), arr.begin() + mid);
    std::vector<int> right(arr.begin() + mid, arr.end());

    // Llamadas recursivas para ordenar las mitades
    mergeInsertionSortVector(left);
    mergeInsertionSortVector(right);

    // Fusionar los sub-vectores ordenados
    mergeVector(arr, left, right);
}

// Función auxiliar para fusionar en std::vector
void PmergeMe::mergeVector(std::vector<int>& arr, const std::vector<int>& left, const std::vector<int>& right) {
    std::vector<int>::size_type i = 0, j = 0, k = 0;
    while (i < left.size() && j < right.size()) {
        if (left[i] < right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }
    while (i < left.size()) {
        arr[k++] = left[i++];
    }
    while (j < right.size()) {
        arr[k++] = right[j++];
    }
}

// Algoritmo Merge-Insertion Sort para std::deque
void PmergeMe::mergeInsertionSortDeque(std::deque<int>& arr) {
    if (arr.size() <= 1) return;

    // Divide el deque en dos sub-deques
    int mid = arr.size() / 2;
    std::deque<int> left(arr.begin(), arr.begin() + mid);
    std::deque<int> right(arr.begin() + mid, arr.end());

    // Llamadas recursivas para ordenar las mitades
    mergeInsertionSortDeque(left);
    mergeInsertionSortDeque(right);

    // Fusionar los sub-deques ordenados
    mergeDeque(arr, left, right);
}

// Función auxiliar para fusionar en std::deque
void PmergeMe::mergeDeque(std::deque<int>& arr, const std::deque<int>& left, const std::deque<int>& right) {
    std::deque<int>::size_type i = 0, j = 0, k = 0;
    while (i < left.size() && j < right.size()) {
        if (left[i] < right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }
    while (i < left.size()) {
        arr[k++] = left[i++];
    }
    while (j < right.size()) {
        arr[k++] = right[j++];
    }
}

// Getters para obtener los contenedores
const std::vector<int>& PmergeMe::getNumbersVector() const {
    return numbersVector;
}

const std::deque<int>& PmergeMe::getNumbersDeque() const {
    return numbersDeque;
}
