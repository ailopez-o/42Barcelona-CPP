#include <iostream>
#include <string>

class Contact
{
	private:
		int	id;
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;
	public:
		void contact(int id);
		void set_first_name(std::string name);
		std::string get_first_name();
		void set_last_name(std::string name);
		std::string get_last_name();
		void set_nickname(std::string name);
		std::string get_nickname();
		void set_phone_number(std::string name);
		std::string get_phone_number();
		void set_darkest_secret(std::string name);
		std::string get_darkest_secret();
};
