#include "iostream"
#include "ScalarConvert.hpp"
#include <unistd.h>
#include <sstream>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout <<  "Takes one input!"  << std::endl;
		return (1);
	}
	try
	{
		std::string str = argv[1];
		ScalarConverter d;
		d.convert(str);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}