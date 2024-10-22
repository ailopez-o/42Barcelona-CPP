#include "rpn.hpp"
#include <sstream>
#include <cctype>

// Constructor que inicializa la expresión
RPN::RPN(const std::string& expr) : expression(expr) {}

// Método para evaluar la expresión RPN
int RPN::evaluate() {
    std::stack<int> stack;  // Pila para almacenar los operandos
    std::istringstream iss(expression);  // Usamos un string stream para procesar la expresión

    std::string token;
    while (iss >> token) {
        if (token.length() == 1 && isOperator(token[0])) {
            // Si es un operador, aplicamos la operación
            if (stack.size() < 2) {
                throw std::runtime_error("Error: not enough operands for operation.");
            }

            int operand2 = stack.top(); stack.pop();
            int operand1 = stack.top(); stack.pop();
            int result = applyOperation(token[0], operand1, operand2);
            stack.push(result);
        } else if (std::isdigit(token[0])) {
            // Si es un número, lo empujamos a la pila
            stack.push(token[0] - '0');  // Convertir carácter a número
        } else {
            throw std::runtime_error("Error: invalid token.");
        }
    }

    // Al final, si la pila tiene exactamente un elemento, ese es el resultado
    if (stack.size() != 1) {
        throw std::runtime_error("Error: invalid expression.");
    }

    return stack.top();  // Devuelve el resultado final
}

// Función para verificar si un carácter es un operador
bool RPN::isOperator(char c) const {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

// Función para aplicar una operación aritmética
int RPN::applyOperation(char op, int operand1, int operand2) {
    switch (op) {
        case '+': return operand1 + operand2;
        case '-': return operand1 - operand2;
        case '*': return operand1 * operand2;
        case '/': 
            if (operand2 == 0) {
                throw std::runtime_error("Error: division by zero.");
            }
            return operand1 / operand2;
        default:
            throw std::runtime_error("Error: invalid operator.");
    }
}
