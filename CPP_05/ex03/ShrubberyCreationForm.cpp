#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), _target(other._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    checkExecutionRequirements(executor);
    std::ofstream file((_target + "_shrubbery").c_str());
    if (file.is_open())
    {
        file << "      /\\\n";
        file << "     /\\*\\\n";
        file << "    /\\O\\*\\\n";
        file << "   /*/\\/\\/\\\n";
        file << "  /\\O\\/\\*\\/\\\n";
        file << " /\\*\\/\\*\\/\\/\\\n";
        file << "/\\O\\/\\/*/\\/O/\\\n";
        file.close();
    }
}
