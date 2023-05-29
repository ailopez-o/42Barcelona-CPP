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

int Contact::SetFirstName(std::string first_name){
	this->first_name = first_name;
	return(EXIT_SUCCESS);
}
int Contact::SetLastName(std::string last_name){
	this->first_name = last_name;
	return(EXIT_SUCCESS);
}
int Contact::SetNickName(std::string nickname){
	this->first_name = nickname;
	return(EXIT_SUCCESS);
}
int Contact::SetPhone(std::string phone_number){
	this->first_name = phone_number;
	return(EXIT_SUCCESS);
}
int Contact::SetSecret(std::string darkest_secret){
	this->first_name = darkest_secret;
	return(EXIT_SUCCESS);
}