#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern Default Constructor Called" << std::endl;
}

Intern::Intern(const Intern& I)
{
	(void)I;
	std::cout << "Intern Copy Constructor Called" << std::endl;
}

Intern& Intern::operator=(const Intern& I)
{
	(void)I;
	std::cout << "Intern Assignment Operator Called" << std::endl;
	return *this;
}

Intern::~Intern()
{
	std::cout << "Intern Destructor Called" << std::endl;
}

AForm* Intern::makeForm(std::string name, std::string target)
{
	AForm *ptr;
	bool isCreated = false;
	std::string Form[3] = {"robotomy request", "shrubbery creation", "presidential pardon"};
	const AForm* formObjects[] = {new RobotomyRequest(), new ShrubberyCreation(), new PresidentialPardon()};
	for(int i = 0; i < 3; i++)
	{
		if(Form[i] == name)
		{
			isCreated = true;
		}
	}
	if(isCreated)
	{
		std::cout << "Intern creates " << ptr->getName() << std::endl;
		return ptr; 
	}
	else
		throw formNotFound();
	
}

const char* Intern::formNotFound::what() const throw()
{
	std::cerr << "Form not found!" << std::endl;
}