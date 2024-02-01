#include "Harl.hpp"

LogLevel getLogLevel(const std::string& level) {
    if (level == "DEBUG") return DEBUG;
    if (level == "INFO") return INFO;
    if (level == "WARNING") return WARNING;
    if (level == "ERROR") return ERROR;
    return INVALID;
}


int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <LOG_LEVEL>\n";
        return 1;
    }
	Harl harl;

    std::string inputLevel(argv[1]);

    LogLevel level = getLogLevel(inputLevel);

    harl.complain(level);

    return 0;
}