#include <iostream>
#include <string>
#include "Phonebook.hpp"

// ------// Class Phonebook

Phonebook::Phonebook()
{
	this->last_index = -1;
	this->num_contacts = 0;
	this->book_name = "phonebook";
}

static std::string get_input(std::string label)
{
	std::string input;
	
	while (input.empty())
	{
		std::cout<<label;
		std::getline(std::cin, input);
		if (!std::cin)
			break;
	}
	return input;
}

int Phonebook::getNumContacts()
{
	return this->num_contacts;
}

int Phonebook::addContact()
{
	Contact &new_contact = searchFreeContact();
	std::cout<<std::endl;

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	new_contact.setFirstName(get_input(" > First Name: "));
	new_contact.setLastName(get_input(" > Last Name: "));
	new_contact.setNickName(get_input(" > Nick Name: "));
	new_contact.setPhone(get_input(" > Phone: "));
	new_contact.setSecret(get_input(" > Darkest Secret: "));
	if (!std::cin)
		return (EXIT_SUCCESS);
	std::cout<<"\n User ["<< new_contact.getFirstName() <<"] added success" << std::endl;
	this->last_index = getNextIndex();
	num_contacts++;
	return(EXIT_SUCCESS);
}

int Phonebook::printContacts()
{
	int num_print;

	if (this->num_contacts == 0)
	{
		std::cout << std::endl << "WARNING: There is no contacts" << std::endl;
		return (EXIT_FAILURE);
	}
	if (this->num_contacts >= MAX_CONTACTS)
		num_print = MAX_CONTACTS;
	else
		num_print = this->num_contacts;
	std::cout<<std::endl;
	for(int i = 0; i < num_print; i++)
	{	
		std::cout<<" "<< i + 1 << " ";
		contacts[i].printView();
	}
	std::cout<<std::endl;
	return (EXIT_SUCCESS);
}

int Phonebook::printContact(int index)
{
	this->contacts[index].printContact();
	return (EXIT_SUCCESS);
}

Contact& Phonebook::searchContact(int index)
{	
	return (this->contacts[index]);
}

int Phonebook::getNextIndex()
{
	if (this->last_index == (MAX_CONTACTS - 1))
		return 0;
	return (this->last_index + 1);
}

Contact& Phonebook::searchFreeContact()
{
	return this->contacts[getNextIndex()];
}
