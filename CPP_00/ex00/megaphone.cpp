#include <iostream>
#include <string>

int		main(int argc, char **argv)
{
	if (argc < 2)
		std::cout<<"* LOUD AND UNBEARABLE FEEDBACK NOISE *"<<std::endl;
	else
	{	int i;
		i = 0;
		while (argv[++i])
		{
			std::string str = argv[i];
			std::transform(str.begin(), str.end(), str.begin(), ::toupper);
			std::cout<<str;
		}
		std::cout<<std::endl;
	}
}