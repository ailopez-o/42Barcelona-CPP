#include <iostream>
#include <string>

int		main(int argc, char **argv)
{
	if (argc != 2)
		std::cout<<"* LOUD AND UNBEARABLE FEEDBACK NOISE *"<<std::endl;
	else
	{
		std::string str = argv[1];

		std::transform(str.begin(), str.end(), str.begin(), ::toupper);
		std::cout<<str<<std::endl;
	}
}