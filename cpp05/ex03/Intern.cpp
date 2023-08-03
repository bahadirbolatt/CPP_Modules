#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

AForm* makeTarget(std::string target, int i)
{
	AForm* formy[3];
	AForm* fo;

	formy[0] = new RobotomyRequestForm();
	formy[1] = new ShrubberyCreationForm();
	formy[2] = new PresidentialPardonForm();
	fo = formy[i]->clone(target);
	delete formy[0];
    delete formy[1];
    delete formy[2];
	return(fo);
}

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
	for(int i = 0; i < 3; i++)
	{
		if(Form[i] == name)
		{
			ptr = makeTarget(target, i);
		}
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