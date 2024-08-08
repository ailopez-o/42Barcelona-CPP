#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include <string>

class Form; // Forward declaration

class Bureaucrat
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
    Bureaucrat(const std::string& name, int grade);

    // Destructor
    ~Bureaucrat();

    // Copy constructor
    Bureaucrat(const Bureaucrat& other);

    // Assignment operator
    Bureaucrat& operator=(const Bureaucrat& other);

    // Getters
    const std::string& getName() const;
    int getGrade() const;

    // Increment grade
    void incrementGrade();

    // Decrement grade
    void decrementGrade();

    // Sign a form
    void signForm(Form& form);

private:
    const std::string _name;
    int _grade;
};

// Overload of the insertion operator
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif // BUREAUCRAT_HPP
