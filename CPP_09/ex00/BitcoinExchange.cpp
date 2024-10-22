#include "BitcoinExchange.hpp"

// Constructor vacío
BitcoinExchange::BitcoinExchange() {}

// Función para validar si una fecha está en formato "YYYY-MM-DD"
bool BitcoinExchange::isValidDate(const std::string& date) const {
    if (date.size() != 10 || date[4] != '-' || date[7] != '-') {
        return false;
    }
    int year, month, day;
    char dash1, dash2;
    std::istringstream iss(date);
    if (!(iss >> year >> dash1 >> month >> dash2 >> day) || dash1 != '-' || dash2 != '-') {
        return false;
    }
    if (month < 1 || month > 12 || day < 1 || day > 31) {
        return false;
    }
    return true;
}

// Función para validar si un valor está en el rango adecuado (entre 0 y 1000)
bool BitcoinExchange::isValidValue(float value) const {
    return value >= 0 && value <= 1000;
}

// Función para encontrar la tasa de cambio más cercana en el pasado
float BitcoinExchange::findClosestRate(const std::string& date) const {
    std::map<std::string, float>::const_iterator it = bitcoinData.lower_bound(date);
    if (it != bitcoinData.end() && it->first == date) {
        return it->second;  // Fecha exacta encontrada
    }
    if (it != bitcoinData.begin()) {
        --it;  // Usar la fecha más cercana en el pasado
    }
    return it->second;
}

// Función para cargar el archivo CSV con las tasas de cambio
bool BitcoinExchange::loadBitcoinData(const std::string& filename) {
    std::ifstream file(filename.c_str());  // En C++98 no se puede pasar std::string directamente a ifstream
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return false;
    }

    std::string line;
    // Leer el CSV línea por línea
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string date;
        float rate;
        if (std::getline(ss, date, ',') && ss >> rate) {
            bitcoinData[date] = rate;
        }
    }

    return true;
}

// Función para procesar el archivo de entrada
void BitcoinExchange::processInput(const std::string& inputFile) const {
    std::ifstream file(inputFile.c_str());  // En C++98, usamos .c_str() para convertir std::string a const char*
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line);  // Omitir la primera línea (cabecera)
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string date, pipe;
        float value;

        if (std::getline(ss, date, ' ') && std::getline(ss, pipe, ' ') && pipe == "|" && ss >> value) {
            if (!isValidDate(date)) {
                std::cerr << "Error: bad input => " << date << std::endl;
            } else if (!isValidValue(value)) {
                std::cerr << "Error: not a valid value => " << value << std::endl;
            } else {
                float rate = findClosestRate(date);
                std::cout << date << " => " << value << " = " << value * rate << std::endl;
            }
        } else {
            std::cerr << "Error: bad input format => " << line << std::endl;
        }
    }
}
