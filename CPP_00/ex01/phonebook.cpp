#include <iostream>
#include <string>
#include "phonebook.hpp"

// ------// Class Phonebook

Phonebook::Phonebook()
{
	this->last_index = -1;
	this->num_contacts = 0;
	this->book_name = "phonebook";
}

Phonebook::Phonebook(const std::string name)
{
	this->last_index = -1;
	this->num_contacts = 0;
	this->book_name = name;
}

static std::string get_input(std::string label)
{
	std::string input;
	
	while (input.empty())
	{
		std::cout<<label;
		std::getline(std::cin, input);
	}
	return input;
}

int Phonebook::GetNumContacts()
{
	return this->num_contacts;
}

int Phonebook::AddContact()
{
	Contact &new_contact = SearchFreeContact();
	std::cout<<std::endl;

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	new_contact.SetFirstName(get_input(" > First Name: "));
	new_contact.SetLastName(get_input(" > Last Name: "));
	new_contact.SetNickName(get_input(" > Nick Name: "));
	new_contact.SetPhone(get_input(" > Phone: "));
	new_contact.SetSecret(get_input(" > Darkest Secret: "));
	std::cout<<"\n User ["<< new_contact.GetFirstName() <<"] added success" << std::endl;
	this->last_index = GetNextIndex();
	num_contacts++;
	return(EXIT_SUCCESS);
}

int Phonebook::PrintContacts()
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
		contacts[i].PrintView();
	}
	std::cout<<std::endl;
	return (EXIT_SUCCESS);
}

int Phonebook::PrintContact(int index)
{
	this->contacts[index].PrintContact();
	return (EXIT_SUCCESS);
}

Contact& Phonebook::SearchContact(int index)
{	
	return (this->contacts[index]);
}

int Phonebook::GetNextIndex()
{
	if (this->last_index == (MAX_CONTACTS - 1))
		return 0;
	return (this->last_index + 1);
}

Contact& Phonebook::SearchFreeContact()
{
	return this->contacts[GetNextIndex()];
}
