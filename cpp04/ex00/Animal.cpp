#include "Animal.hpp"
#include <iostream>

Animal::Animal()
{
    Animal::type = "Animal";
    std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal& oth)
{
    *this = oth;
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal::Animal(std::string type) : type(type)
{
	std::cout << "Animal Name Constructor Called" << std::endl;
}

Animal &Animal::operator=(Animal const &temp)
{
    if(this != &temp)
    {
        this->type = temp.type;
    }
    return (*this);
}

Animal::~Animal(){std::cout << "Animal destructor called" << std::endl;}

std::string Animal::getType() const// getter
{
    return(this->type);
}

void Animal::makeSound() const {
    std::cout << "Animal made a sound." << std::endl;
}

Animal &operator=(const Animal& oth)
{
    if(this != &oth)
        this->type = oth.type;
    std::cout << "Bureaucrat assignment operator called" << std::endl;
    return(*this);
}