#include "phonebook.hpp"

// ------// Class Phonebook

Phonebook::Phonebook()
{
	this->book_name = "phonebook";
}

Phonebook::Phonebook(const std::string name)
{
	this->book_name = name;
}

int Phonebook::AddContact()
{
	std::string input;
	Contact new_contact = SearchFreeContact();

	std::cout<<"First Name: ";
	std::cin>>input;
	new_contact.SetFirstName(input);
	std::cout<<"Last Name: ";
	std::cin>>input;
	new_contact.SetLastName(input);
	std::cout<<"Nick Name: ";
	std::cin>>input;
	new_contact.SetNickName(input);
	std::cout<<"Phone: ";
	std::cin>>input;
	new_contact.SetPhone(input);
	std::cout<<"Darkest Secret: ";
	std::cin>>input;
	new_contact.SetSecret(input);
	return(EXIT_SUCCESS);
}

Contact& Phonebook::SearchContact(int index)
{	
	return (this->contacts[index]);
}

Contact& Phonebook::SearchFreeContact()
{
	return (this->contacts[0]);
}
