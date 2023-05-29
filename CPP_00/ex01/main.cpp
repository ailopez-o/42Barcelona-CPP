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
	std::cout<<"########   Select an option ############"<<std::endl;
	std::cout<<"ADD"<<std::endl;
	std::cout<<"SEARCH"<<std::endl;
	std::cout<<"EXIT"<<std::endl;
	std::cout<<"Your selection: ";
	std::cin>>input;
	if (!input.compare("EXIT"))
		break;
	else if (!input.compare("ADD"))
		std::cout<<"ADD selected"<<std::endl;
	else if (!input.compare("SEARCH"))
		std::cout<<"SEARCH selected"<<std::endl;
	else
		std::cout<<"INVALID selection"<<std::endl;
}

	delete (my_phonebook);
}