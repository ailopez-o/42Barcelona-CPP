#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <stdexcept>

class RPN {
public:
    // Constructor que toma una expresión RPN como cadena de caracteres
    RPN(const std::string& expression);

    // Método para evaluar la expresión RPN
    int evaluate();

private:
    std::string expression;  // Expresión RPN a evaluar

    // Método auxiliar para procesar cada token
    void processToken(const std::string& token, std::stack<int>& stack);

    // Función auxiliar para verificar si un carácter es un operador
    bool isOperator(char c) const;

    // Función auxiliar para aplicar una operación
    int applyOperation(char op, int operand1, int operand2);
};

#endif
