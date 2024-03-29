#include <iostream>
#include <string>
#include "Phonebook.hpp"
#include "Contact.hpp"

int		main(void)
{
	std::string input;
	int num_select;
	Phonebook* my_phonebook;
	my_phonebook = new Phonebook();


while (std::cin)
{
	input.erase();
	std::cout<<"\n########   Select an option ############\n"<<std::endl;
	std::cout<<":: ADD"<<std::endl;
	std::cout<<":: SEARCH"<<std::endl;
	std::cout<<":: EXIT"<<std::endl;
	while (input.empty())
	{
		std::cout<<std::endl<<"Your selection: ";
		std::cin >> input;
		if (!std::cin)
			break;
	}
	if (!input.compare("EXIT"))
		break;
	else if (!input.compare("ADD"))
	{
		my_phonebook->addContact();
		input.erase();
	}
	else if (!input.compare("SEARCH"))
	{
		if (my_phonebook->printContacts() != 1)
		{
			std::cout<<"Your choice: ";
    		std::cin >> num_select;
			std::cout<<std::endl;
        	if (std::cin.good() && (num_select <= my_phonebook->getNumContacts())) 
				my_phonebook->printContact(num_select - 1);
			else
			{
				std::cout<<"WARNING: Out of range " << std::endl;
				std::cin.clear();
            	std::cin.ignore(1000,'\n');
			}
		}
		input.erase();
	}
	else
	{
		std::cout<<"INVALID selection"<<std::endl;
		input.erase();
	}
}
	delete (my_phonebook);
	return (0);
}
