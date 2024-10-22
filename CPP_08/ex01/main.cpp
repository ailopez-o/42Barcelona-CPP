#include "span.tpp"

int main() {
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

        // Inicializar un vector de manera compatible con C++98
        std::vector<int> range;
        range.push_back(100);
        range.push_back(200);
        range.push_back(300);
        range.push_back(400);
        range.push_back(500);

        // Prueba para agregar un rango de números
        Span spRange(10);
        spRange.addRange(range.begin(), range.end());

        spRange.addNumber(50); // Agregar más números para probar
        std::cout << "Shortest Span (Range): " << spRange.shortestSpan() << std::endl;
        std::cout << "Longest Span (Range): " << spRange.longestSpan() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Excepción capturada: " << e.what() << std::endl;
    }

    return 0;
}

