#include <iostream>
#include <string>


class Phonebook
{
	private:
		std::string	name;
		Contact	contacts[8];
	public:
		void phonebook(std::string name);
};

