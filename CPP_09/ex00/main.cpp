#include "BitcoinExchange.hpp"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Error: incorrect number of arguments." << std::endl;
        return 1;
    }

    BitcoinExchange btcExchange;

    // Cargar los datos de Bitcoin desde el archivo CSV
    if (!btcExchange.loadBitcoinData("data.csv")) {
        return 1;
    }

    // Procesar el archivo de entrada
    btcExchange.processInput(argv[1]);

    return 0;
}
