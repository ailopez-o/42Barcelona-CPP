#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void testIntern()
{
    Intern someRandomIntern;
    AForm* form;

    form = someRandomIntern.makeForm("robotomy request", "Bender");
    if (form) {
        Bureaucrat bob("Bob", 45);
        bob.signForm(*form);
        bob.executeForm(*form);
        delete form;
    }

    form = someRandomIntern.makeForm("shrubbery creation", "home");
    if (form) {
        Bureaucrat alice("Alice", 1);
        alice.signForm(*form);
        alice.executeForm(*form);
        delete form;
    }

    form = someRandomIntern.makeForm("presidential pardon", "Ford");
    if (form) {
        Bureaucrat charlie("Charlie", 1);
        charlie.signForm(*form);
        charlie.executeForm(*form);
        delete form;
    }

    // Intentar crear un formulario no existente
    form = someRandomIntern.makeForm("nonexistent form", "Nobody");
    if (!form) {
        std::cout << "Form creation failed as expected." << std::endl;
    }
}

int main()
{
    testIntern();
    return 0;
}
