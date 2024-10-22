#include "rpn.hpp"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Error: incorrect number of arguments." << std::endl;
        return 1;
    }

    try {
        RPN calculator(argv[1]);  // Inicializar la calculadora con la expresión
        int result = calculator.evaluate();  // Evaluar la expresión
        std::cout << result << std::endl;  // Mostrar el resultado
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;  // Manejar los errores
        return 1;
    }

    return 0;
}
