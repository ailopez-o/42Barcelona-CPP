#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include "Contact.hpp"

#define	MAX_CONTACTS 8

class Phonebook
{
	private:
		std::string	book_name;
		int	last_index;
		int	num_contacts;
		Contact	contacts[MAX_CONTACTS];
		Contact& searchFreeContact();
		int getNextIndex();

	public:
		Phonebook();
		int printContacts();
		int printContact(int index);
		int addContact();
		int getNumContacts();
		Contact& searchContact(int index);
};

#endif // PHONEBOOK_HPP
