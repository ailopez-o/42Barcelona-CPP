#include "AForm.hpp"

// Implementación de las excepciones
const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low!";
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return "Form is not signed!";
}

// Constructor
AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (_gradeToSign < 1 || _gradeToExecute < 1)
        throw GradeTooHighException();
    if (_gradeToSign > 150 || _gradeToExecute > 150)
        throw GradeTooLowException();
}

// Destructor
AForm::~AForm() {}

// Constructor de copia
AForm::AForm(const AForm& other)
    : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}

// Operador de asignación
AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
    {
        _isSigned = other._isSigned;
    }
    return *this;
}

// Getters
const std::string& AForm::getName() const { return _name; }
bool AForm::isSigned() const { return _isSigned; }
int AForm::getGradeToSign() const { return _gradeToSign; }
int AForm::getGradeToExecute() const { return _gradeToExecute; }

// Ser firmado por un burócrata
void AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _isSigned = true;
}

// Comprobar requisitos de ejecución
void AForm::checkExecutionRequirements(const Bureaucrat& executor) const
{
    if (!_isSigned)
        throw FormNotSignedException();
    if (executor.getGrade() > _gradeToExecute)
        throw GradeTooLowException();
}

// Sobrecarga del operador de inserción
std::ostream& operator<<(std::ostream& os, const AForm& form)
{
    os << "Form " << form.getName() << ", signed: " << (form.isSigned() ? "yes" : "no")
       << ", grade required to sign: " << form.getGradeToSign()
       << ", grade required to execute: " << form.getGradeToExecute();
    return os;
}
