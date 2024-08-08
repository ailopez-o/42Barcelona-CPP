#include "Intern.hpp"

// Constructor
Intern::Intern() {}

// Destructor
Intern::~Intern() {}

// Constructor de copia
Intern::Intern(const Intern& other) { (void)other; }

// Operador de asignación
Intern& Intern::operator=(const Intern& other) { (void)other; return *this; }

// Tabla de funciones para la creación de formularios
const Intern::FormType Intern::formTypes[3] = {
    {"shrubbery creation", &Intern::createShrubberyCreationForm},
    {"robotomy request", &Intern::createRobotomyRequestForm},
    {"presidential pardon", &Intern::createPresidentialPardonForm}
};

// Métodos de creación de formularios
AForm* Intern::createShrubberyCreationForm(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyRequestForm(const std::string& target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardonForm(const std::string& target) {
    return new PresidentialPardonForm(target);
}

// Método principal para crear formularios
AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
    for (int i = 0; i < 3; ++i) {
        if (formTypes[i].name == formName) {
            std::cout << "Intern creates " << formName << std::endl;
            return formTypes[i].create(target);
        }
    }
    std::cout << "Error: Form name " << formName << " not recognized." << std::endl;
    return NULL;
}
