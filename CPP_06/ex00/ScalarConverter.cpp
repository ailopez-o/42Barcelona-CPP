#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) { (void)other; return *this; }
ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string& literal)
{
    char* end;
    double value = std::strtod(literal.c_str(), &end);

    if (literal.length() == 1 && !std::isdigit(literal[0])) {
        // Case for single character
        value = static_cast<double>(literal[0]);
    } else if (end == literal.c_str() || errno == ERANGE || *end != '\0') {
        // Check for invalid conversion
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: impossible\n";
        std::cout << "double: impossible\n";
        return;
    }

    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}

void ScalarConverter::printChar(double value)
{
    if (std::isnan(value) || std::isinf(value) || value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max()) {
        std::cout << "char: impossible\n";
    } else {
        char c = static_cast<char>(value);
        if (std::isprint(c)) {
            std::cout << "char: '" << c << "'\n";
        } else {
            std::cout << "char: Non displayable\n";
        }
    }
}

void ScalarConverter::printInt(double value)
{
    if (std::isnan(value) || std::isinf(value) || value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max()) {
        std::cout << "int: impossible\n";
    } else {
        int i = static_cast<int>(value);
        std::cout << "int: " << i << '\n';
    }
}

void ScalarConverter::printFloat(double value)
{
    if (std::isnan(value)) {
        std::cout << "float: nanf\n";
    } else if (std::isinf(value)) {
        std::cout << "float: " << (value > 0 ? "+inff" : "-inff") << '\n';
    } else if (value < -std::numeric_limits<float>::max() || value > std::numeric_limits<float>::max()) {
        std::cout << "float: impossible\n";
    } else {
        float f = static_cast<float>(value);
        std::cout << "float: " << f << "f\n";
    }
}

void ScalarConverter::printDouble(double value)
{
    if (std::isnan(value)) {
        std::cout << "double: nan\n";
    } else if (std::isinf(value)) {
        std::cout << "double: " << (value > 0 ? "+inf" : "-inf") << '\n';
    } else {
        std::cout << "double: " << value << '\n';
    }
}
