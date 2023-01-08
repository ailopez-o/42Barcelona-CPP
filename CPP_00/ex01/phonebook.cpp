#include "phonebook.hpp"

// ------// Class Phonebook

void Phonebook::phonebook(std::string name)
{
	this->name = name;
}

// ------// Class Contact

void Contact::contact(int id)
{
	this->id = id;
}

void	Contact::set_first_name(std::string name)
{
	this->first_name = name;
}

std::string	Contact::get_first_name()
{
	return (first_name);
}
