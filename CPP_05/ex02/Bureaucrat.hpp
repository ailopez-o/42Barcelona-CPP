#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include <string>

class AForm; // Declaración anticipada de la clase AForm

class Bureaucrat
{
public:
    // Clases de excepción
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

    // Constructor de copia
    Bureaucrat(const Bureaucrat& other);

    // Operador de asignación
    Bureaucrat& operator=(const Bureaucrat& other);

    // Getters
    const std::string& getName() const;
    int getGrade() const;

    // Incrementar y decrementar el grado
    void incrementGrade();
    void decrementGrade();

    // Firmar un formulario
    void signForm(AForm& form);

    // Ejecutar un formulario
    void executeForm(AForm const & form) const;

private:
    const std::string _name;
    int _grade;
};

// Sobrecarga del operador de inserción
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif // BUREAUCRAT_HPP
