#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include "contact.hpp"

#define	MAX_CONTACTS 8

class Phonebook
{
	private:
		std::string	book_name;
		int	last_index;
		int	num_contacts;
		Contact	contacts[MAX_CONTACTS];
		Contact& SearchFreeContact();
		int GetNextIndex();

	public:
		Phonebook();
		Phonebook(std::string name);
		int PrintContacts();
		int PrintContact(int index);
		int AddContact();
		int GetNumContacts();
		Contact& SearchContact(int index);
};

#endif // PHONEBOOK_HPP
