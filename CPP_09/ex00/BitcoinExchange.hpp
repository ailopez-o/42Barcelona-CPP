#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

class BitcoinExchange {
private:
    std::map<std::string, float> bitcoinData;

    // Función para validar si una fecha está en formato "YYYY-MM-DD"
    bool isValidDate(const std::string& date) const;

    // Función para validar si un valor está en el rango adecuado (entre 0 y 1000)
    bool isValidValue(float value) const;

    // Función para encontrar la tasa de cambio más cercana en el pasado
    float findClosestRate(const std::string& date) const;

public:
    // Constructor vacío
    BitcoinExchange();

    // Función para cargar el archivo CSV con las tasas de cambio
    bool loadBitcoinData(const std::string& filename);

    // Función para procesar el archivo de entrada
    void processInput(const std::string& inputFile) const;
};

#endif
