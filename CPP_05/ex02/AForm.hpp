#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <stdexcept>
#include <string>
#include "Bureaucrat.hpp"

class AForm
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

    class FormNotSignedException : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };

    // Constructor
    AForm(const std::string& name, int gradeToSign, int gradeToExecute);

    // Destructor
    virtual ~AForm();

    // Constructor de copia
    AForm(const AForm& other);

    // Operador de asignación
    AForm& operator=(const AForm& other);

    // Getters
    const std::string& getName() const;
    bool isSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    // Ser firmado por un burócrata
    void beSigned(const Bureaucrat& bureaucrat);

    // Método virtual puro para ejecutar la acción del formulario
    virtual void execute(Bureaucrat const & executor) const = 0;

protected:
    void checkExecutionRequirements(const Bureaucrat& executor) const;

private:
    const std::string _name;
    bool _isSigned;
    const int _gradeToSign;
    const int _gradeToExecute;
};

// Sobrecarga del operador de inserción
std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif // AFORM_HPP
