#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP

#include "MutantStack.hpp"

template<typename T>
MutantStack<T>::MutantStack(){
    std::cout << "MutantStack default constructor called" << std::endl;
}

template<typename T>
MutantStack<T>::MutantStack(const MutantStackk& copy){
    std::cout << "MutantStack copy constructor called" << std::endl;
}

template<typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& copy){
    if(this != &copy)
        this->c = copy.c;
    std::cout << "MutantStack copy assignment operator called" << std::endl;
    return *this;
}

template<typename T>
MutantStack<T>::~MutantStack(){
    this->c.clear();
    std::cout << "MutantStack destructor called" << std::endl;
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end(){
    return this->c.end();
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin(){
    return this->c.begin();
}
template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() const{
    return this->c.begin();
}
template<typename T> // neden const ve c nerede tanimli?
typename MutantStack<T>::iterator MutantStack<T>::end() const{
    return this->c.end();
}

#endif