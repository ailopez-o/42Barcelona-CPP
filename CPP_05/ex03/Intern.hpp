#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
public:
    Intern();
    ~Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);

    AForm* makeForm(const std::string& formName, const std::string& target);

private:
    struct FormType {
        std::string name;
        AForm* (*create)(const std::string&);
    };

    static AForm* createShrubberyCreationForm(const std::string& target);
    static AForm* createRobotomyRequestForm(const std::string& target);
    static AForm* createPresidentialPardonForm(const std::string& target);

    static const FormType formTypes[3];
};

#endif // INTERN_HPP
