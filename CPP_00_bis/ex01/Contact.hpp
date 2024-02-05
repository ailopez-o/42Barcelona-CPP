#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact
{
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;
		bool b_available;
	public:
		int contact();
		int contact(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string darkest_secret);
		int setFirstName(std::string first_name);
		int setLastName(std::string last_name);
		int setNickName(std::string nickname);
		int setPhone(std::string phone_number);
		int setSecret(std::string darkest_secret);
		int setAvailable(bool value);
		std::string getFirstName();
		bool getAvailable();
		int printView();
		int printContact();

};

#endif // CONTACT_HPP


