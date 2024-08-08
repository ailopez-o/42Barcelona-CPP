#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void testForms()
{
    try
    {
        Bureaucrat alice("Alice", 1);
        ShrubberyCreationForm shrubbery("home");
        RobotomyRequestForm robotomy("Bender");
        PresidentialPardonForm pardon("Ford");

        alice.signForm(shrubbery);
        alice.executeForm(shrubbery);

        alice.signForm(robotomy);
        alice.executeForm(robotomy);

        alice.signForm(pardon);
        alice.executeForm(pardon);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat bob("Bob", 150);
        ShrubberyCreationForm shrubbery("office");

        bob.signForm(shrubbery); // Debería lanzar GradeTooLowException
        bob.executeForm(shrubbery);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat charlie("Charlie", 45);
        RobotomyRequestForm robotomy("John");

        charlie.signForm(robotomy);
        charlie.executeForm(robotomy); // Debería ejecutarse correctamente
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat david("David", 5);
        PresidentialPardonForm pardon("Arthur");

        david.signForm(pardon);
        david.executeForm(pardon); // Debería ejecutarse correctamente
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

int main()
{
    testForms();
    return 0;
}
/*  */