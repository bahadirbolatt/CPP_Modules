#include "Form.hpp"

int main(void)
{
	Bureaucrat b1("b1", 5);
	Bureaucrat b2("b2", 10);

	try
	{
		std::cout << "=========Test 1=========" << std::endl;
		Form f1("f1", 50, 50);
		// Form f2("f2", 100, 151);

		std::cout << f1 << std::endl;
		std::cout << std::endl;
		// std::cout << f2 << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		std::cout << "=========Test 2=========" << std::endl;
		Form f3("f3", 50, 30);
		Form f4 = f3;
		f3.beSigned(b1);
		f4.beSigned(b2);
 
		b1.signForm(f3);
		b2.signForm(f4);
		std::cout << std::endl;
 
		std::cout << f3 << std::endl;
		std::cout << std::endl;
		std::cout << f4 << std::endl;
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		std::cout << "=========Test 3=========" << std::endl;
		Form f5("f5", 50, 111);
		f5.beSigned(b2);

		b2.signForm(f5);
		std::cout << std::endl;

		std::cout << f5 << std::endl;
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}