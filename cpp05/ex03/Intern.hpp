#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include <iostream>

class Intern
{
    public:
        Intern();
        Intern(const Intern& internCopy);
        Intern& operator=(const Intern& internCopy);
        ~Intern();

        AForm* makeForm(std::string name, std::string target);
        class formNotFound : public std::exception
        {
            const char * what() const throw();
        };
};

#endif