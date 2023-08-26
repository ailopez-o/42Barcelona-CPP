#include <iostream>
#include <string>
#include "phonebook.hpp"

// ------// Class Phonebook

Phonebook::Phonebook()
{
	this->last_index = -1;
	this->num_comntacts = 0;
	this->book_name = "phonebook";
}

Phonebook::Phonebook(const std::string name)
{
	this->last_index = -1;
	this->num_comntacts = 0;
	this->book_name = name;
}

int Phonebook::AddContact()
{
	std::string input;
	Contact &new_contact = SearchFreeContact();
	std::cout<<std::endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout<<" > First Name: ";
	std::getline(std::cin, input);
	new_contact.SetFirstName(input);
	std::cout<<" > Last Name: ";
	std::getline(std::cin, input);
	new_contact.SetLastName(input);
	std::cout<<" > Nick Name: ";
	std::getline(std::cin, input);
	new_contact.SetNickName(input);
	std::cout<<" > Phone: ";
	std::getline(std::cin, input);
	new_contact.SetPhone(input);
	std::cout<<" > Darkest Secret: ";
	std::getline(std::cin, input);
	new_contact.SetSecret(input);
	std::cout<<"\n User ["<< new_contact.GetFirstName() <<"] added success" << std::endl;
	this->last_index = GetNextIndex();
	num_comntacts++;
	return(EXIT_SUCCESS);
}

int Phonebook::PrintContacts()
{
	int num_print;

	if (this->num_comntacts >= MAX_CONTACTS)
		num_print = MAX_CONTACTS;
	else
		num_print = this->num_comntacts;
	std::cout<<std::endl;
	for(int i = 0; i < num_print; i++)
		contacts[i].PrintView();
	std::cout<<std::endl;
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
