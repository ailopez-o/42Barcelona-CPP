#include "Harl.hpp"



void Harl::debug(void) 
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void) 
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void) 
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void) 
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(LogLevel level) {
	switch (level) {
        case DEBUG:
            std::cout << "[ DEBUG ]\n";
			debug();
            // No hay break aquí para permitir que la ejecución continúe a los siguientes niveles
        case INFO:
            std::cout << "[ INFO ]\n";
			info();
            // No hay break aquí para permitir que la ejecución continúe a los siguientes niveles
        case WARNING:
            std::cout << "[ WARNING ]\n";
			warning();
            // No hay break aquí para permitir que la ejecución continúe al siguiente nivel
        case ERROR:
            std::cout << "[ ERROR ]\n";
			error();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]\n";
            break;
    }
}
