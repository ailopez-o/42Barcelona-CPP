#include "Form.hpp"

// GradeTooHighException
const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high!";
}

// GradeTooLowException
const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low!";
}

// Constructor
Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) 
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (_gradeToSign < 1 || _gradeToExecute < 1)
        throw GradeTooHighException();
    if (_gradeToSign > 150 || _gradeToExecute > 150)
        throw GradeTooLowException();
}

// Destructor
Form::~Form() {}

// Copy constructor
Form::Form(const Form& other) 
    : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}

// Assignment operator
Form& Form::operator=(const Form& other)
{
    if (this != &other)
    {
        // _name, _gradeToSign, and _gradeToExecute are constants, cannot be assigned
        _isSigned = other._isSigned;
    }
    return *this;
}

// Getters
const std::string& Form::getName() const { return _name; }
bool Form::isSigned() const { return _isSigned; }
int Form::getGradeToSign() const { return _gradeToSign; }
int Form::getGradeToExecute() const { return _gradeToExecute; }

// Be signed by a bureaucrat
void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _isSigned = true;
}

// Overload of the insertion operator
std::ostream& operator<<(std::ostream& os, const Form& form)
{
    os << "Form " << form.getName() << ", signed: " << (form.isSigned() ? "yes" : "no")
       << ", grade required to sign: " << form.getGradeToSign()
       << ", grade required to execute: " << form.getGradeToExecute();
    return os;
}
