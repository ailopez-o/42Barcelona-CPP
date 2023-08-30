#include <iostream>
#include <string>
#include "phonebook.hpp"
#include "contact.hpp"

int		main(void)
{
	std::string input;
	int num_select;
	Phonebook* my_phonebook;
	my_phonebook = new Phonebook("CPP00");


while (true)
{
	input.erase();
	std::cout<<"\n########   Select an option ############\n"<<std::endl;
	std::cout<<":: ADD"<<std::endl;
	std::cout<<":: SEARCH"<<std::endl;
	std::cout<<":: EXIT"<<std::endl;
	while (input.empty())
	{
		std::cout<<std::endl<<"Your selection: ";
		getline(std::cin, input);
	}
	if (!input.compare("EXIT"))
		break;
	else if (!input.compare("ADD"))
	{
		my_phonebook->AddContact();
		input.erase();
	}
	else if (!input.compare("SEARCH"))
	{
		if (my_phonebook->PrintContacts() != EXIT_FAILURE)
		{
			std::cout<<"Your choice: ";
			std::cin >> num_select;
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			if (num_select <= my_phonebook->GetNumContacts() && num_select > 0)
			{
				my_phonebook->PrintContact(num_select - 1);
			}
			else
				std::cout<<"WARNING: Out of range ";
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
}