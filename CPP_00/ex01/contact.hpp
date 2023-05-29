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
	public:
		Contact();
		Contact(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string darkest_secret);
		int SetFirstName(std::string first_name);
		int SetLastName(std::string last_name);
		int SetNickName(std::string nickname);
		int SetPhone(std::string phone_number);
		int SetSecret(std::string darkest_secret);

};

#endif // CONTACT_HPP


