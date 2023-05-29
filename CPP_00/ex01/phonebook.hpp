#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include "contact.hpp"


class Phonebook
{
	private:
		std::string	book_name;
		Contact	contacts[8];
		Contact& SearchFreeContact();
	public:
		Phonebook();
		Phonebook(std::string name);
		int AddContact();
		Contact& SearchContact(int index);
};

#endif // PHONEBOOK_HPP
