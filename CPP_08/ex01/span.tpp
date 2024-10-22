#include <iostream>
#include <vector>
#include <algorithm> // Para std::sort, std::min_element, std::max_element
#include <stdexcept> // Para excepciones std::exception
#include <iterator>  // Para std::distance

class Span {
private:
    unsigned int maxSize;       // Tamaño máximo que puede almacenar el Span
    std::vector<int> numbers;   // Contenedor para almacenar los números

public:
    // Constructor que inicializa el tamaño máximo
    Span(unsigned int N) : maxSize(N) {}

    // Función para agregar un número
    void addNumber(int num) {
        if (numbers.size() >= maxSize) {
            throw std::overflow_error("Cannot add more numbers, Span is full.");
        }
        numbers.push_back(num);
    }

    // Función para agregar una secuencia de números usando iteradores
    template <typename InputIterator>
    void addRange(InputIterator begin, InputIterator end) {
        if (std::distance(begin, end) + numbers.size() > maxSize) {
            throw std::overflow_error("Cannot add range, Span will overflow.");
        }
        numbers.insert(numbers.end(), begin, end);
    }

    // Función para encontrar el menor span
    int shortestSpan() {
        if (numbers.size() < 2) {
            throw std::logic_error("Not enough numbers to find a span.");
        }

        // Ordenar el contenedor para encontrar las diferencias mínimas
        std::vector<int> sortedNumbers = numbers;
        std::sort(sortedNumbers.begin(), sortedNumbers.end());

        // Encuentra el menor span comparando diferencias adyacentes
        int minSpan = sortedNumbers[1] - sortedNumbers[0];
        for (size_t i = 1; i < sortedNumbers.size() - 1; ++i) {
            minSpan = std::min(minSpan, sortedNumbers[i + 1] - sortedNumbers[i]);
        }
        return minSpan;
    }

    // Función para encontrar el mayor span
    int longestSpan() {
        if (numbers.size() < 2) {
            throw std::logic_error("Not enough numbers to find a span.");
        }

        // El mayor span es la diferencia entre el valor máximo y el valor mínimo
        int minElement = *std::min_element(numbers.begin(), numbers.end());
        int maxElement = *std::max_element(numbers.begin(), numbers.end());
        return maxElement - minElement;
    }
};
