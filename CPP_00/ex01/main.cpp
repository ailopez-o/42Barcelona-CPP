#include <iostream>
#include <string>
#include "phonebook.hpp"
#include "contact.hpp"

int		main(void)
{
	std::string input = "";
	Phonebook* my_phonebook;
	my_phonebook = new Phonebook("CPP00");


while (true)
{
	std::cout<<"\n########   Select an option ############\n"<<std::endl;
	std::cout<<":: ADD"<<std::endl;
	std::cout<<":: SEARCH"<<std::endl;
	std::cout<<":: EXIT"<<std::endl;
	std::cout<<"\nYour selection: ";
	std::cin>>input;
	if (!input.compare("EXIT"))
		break;
	else if (!input.compare("ADD"))
		my_phonebook->AddContact();
	else if (!input.compare("SEARCH"))
		my_phonebook->PrintContacts();
	else
		std::cout<<"INVALID selection"<<std::endl;
}
	delete (my_phonebook);
}