#include <iomanip>
#include "contact.hpp"

// ------// Class Contact

Contact::Contact()
{
	this->first_name = "";
	this->last_name = "";
	this->nickname = "";
	this->phone_number = "";
	this->darkest_secret = "";
}

Contact::Contact(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string darkest_secret)
{
	this->first_name = first_name;
	this->last_name = last_name;
	this->nickname = nickname;
	this->phone_number = phone_number;
	this->darkest_secret = darkest_secret;
}

bool Contact::GetAvailable()
{
	return(this->b_available);
}

int Contact::SetAvailable(bool value)
{	
	this->b_available = value;
	return(EXIT_SUCCESS);
}

std::string Contact::GetFirstName()
{
	return(this->first_name);
}

int Contact::SetFirstName(std::string first_name)
{
	this->first_name = first_name;
	return(EXIT_SUCCESS);
}
int Contact::SetLastName(std::string last_name)
{
	this->last_name = last_name;
	return(EXIT_SUCCESS);
}
int Contact::SetNickName(std::string nickname)
{
	this->nickname = nickname;
	return(EXIT_SUCCESS);
}
int Contact::SetPhone(std::string phone_number)
{
	this->phone_number = phone_number;
	return(EXIT_SUCCESS);
}
int Contact::SetSecret(std::string darkest_secret)
{
	this->darkest_secret = darkest_secret;
	return(EXIT_SUCCESS);
}

std::string str_truncate(std::string str, unsigned int len)
{
	if (str.length() > len)
		return (str.substr(0, len -1) + ".");
	else
		return(str);
}

int Contact::PrintContact()
{
	std::cout<<"********************************************************" << std::endl;
	std::cout<<" > First Name      : " << this->first_name << std::endl;
	std::cout<<" > Last Name       : " << this->last_name << std::endl;
	std::cout<<" > Nickname        : " << this->nickname << std::endl;
	std::cout<<" > Phone           : " << this->phone_number << std::endl;
	std::cout<<" > Darkest Secret  : " << this->darkest_secret << std::endl;
	std::cout<<"********************************************************" << std::endl;
	return(EXIT_SUCCESS);
}


int Contact::PrintView()
{
    std::cout << " | " << std::setw(10) << str_truncate(this->first_name, 10);
    std::cout << " | " << std::setw(10) << str_truncate(this->last_name, 10);
    std::cout << " | " << std::setw(10) << str_truncate(this->nickname, 10);
	std::cout << " | "<<std::endl;
	return (EXIT_SUCCESS);
}