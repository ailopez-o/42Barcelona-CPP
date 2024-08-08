#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <stdexcept>
#include <string>
#include "Bureaucrat.hpp"

class Form
{
public:
    // Exception classes
    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };

    // Constructor
    Form(const std::string& name, int gradeToSign, int gradeToExecute);

    // Destructor
    ~Form();

    // Copy constructor
    Form(const Form& other);

    // Assignment operator
    Form& operator=(const Form& other);

    // Getters
    const std::string& getName() const;
    bool isSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    // Be signed by a bureaucrat
    void beSigned(const Bureaucrat& bureaucrat);

private:
    const std::string _name;
    bool _isSigned;
    const int _gradeToSign;
    const int _gradeToExecute;
};

// Overload of the insertion operator
std::ostream& operator<<(std::ostream& os, const Form& form);

#endif // FORM_HPP
