#include "Bureaucrat.hpp"
#include "Form.hpp"

void testBureaucratAndForm()
{
    try
    {
        Bureaucrat b1("Alice", 1);
        std::cout << b1 << std::endl;
        
        Form f1("FormA", 1, 1);
        std::cout << f1 << std::endl;

        b1.signForm(f1);
        std::cout << f1 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat b2("Bob", 150);
        std::cout << b2 << std::endl;
        
        Form f2("FormB", 100, 50);
        std::cout << f2 << std::endl;

        b2.signForm(f2); // Should throw GradeTooLowException
        std::cout << f2 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try
    {
        Form f3("FormC", 0, 150); // Should throw GradeTooHighException
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try
    {
        Form f4("FormD", 151, 150); // Should throw GradeTooLowException
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

int main()
{
    testBureaucratAndForm();
    return 0;
}
