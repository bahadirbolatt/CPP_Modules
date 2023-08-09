#include "Span.hpp"

Span::Span() : count(0){
    std::cout << "Span default constructor called" << std::endl;
}

Span::Span(unsigned int N) : count(N){
    std::cout << "Span parameter constructor called" << std::endl;
}

Span::Span(const Span& spanCopy){
    for(unsigned int i = 0; i < spanCopy.vec.size(); i++)
        vec.push_back(spanCopy.vec.at(i));
    std::cout << "Span copy constructor called" << std::endl;
}

Span& Span::operator=(const Span& spanCopy){
    count = spanCopy.count;
    for (unsigned int i = 0; i < spanCopy.vec.size(); i++)
        vec.push_back(spanCopy.vec.at(i));
    std::cout << "Span Copy constructor called" << std::endl;
    return *this;
}

Span::~Span(){
    std::cout << "Span destructor called" << std::endl;
}

void Span::addNumber(unsigned int number)
{
    if(vec.size() >= count)
        throw noStorageLeft();
    vec.push_back(number);
}

void Span::addManyNumber(unsigned int number){  
    if(vec.size() + number > count)
        throw noStorageLeft();
    srand(time(0));
    for(unsigned int i = 0; i < number; i++){
        int randomNumber = rand() % 10001;
        vec.push_back(randomNumber);
    }
}

int Span::longestSpan(){
    if(vec.size() <= 1)
        throw notEnoughNumbers();
    int maxSpan = 0;
    for(std::vector<int>::const_iterator it1 = vec.begin(); it1 != vec.end(); it1++){
        for(std::vector<int>::const_iterator it2 = vec.begin(); it2 != vec.end(); it2++){
            if (it1 != it2) {
                int currentSpan = std::abs(*it1 - *it2); // absolute value(mutlak deger)
                if (currentSpan > maxSpan){
                    maxSpan = currentSpan;
                }
            }
        }
    }
    return maxSpan;
}

int Span::shortestSpan(){
    if(vec.size() <= 1)
        throw notEnoughNumbers();
    int minSpan = 0;
    for(std::vector<int>::const_iterator it1 = vec.begin(); it1 != vec.end(); it1++){
        for(std::vector<int>::const_iterator it2 = vec.begin(); it2 != vec.end(); it2++){
            if (it1 != it2) {
                int currentSpan = std::abs(*it1 - *it2);
                if (currentSpan < minSpan){
                    minSpan = currentSpan;
                }
            }
        }
    }
    return minSpan;
}

std::vector<int> &Span::getVector(){
    return(this->vec);
}

void Span::printData(void){
    for(unsigned int i = 0; i < vec.size(); i++)
        std::cout << vec.at(i) << " ";
}

const char* Span::noStorageLeft::what() const throw()
{
	std::cerr << "No storage Left!" << std::endl;
}

const char* Span::notEnoughNumbers::what() const throw()
{
	std::cerr << "Not enough numbers!" << std::endl;
}