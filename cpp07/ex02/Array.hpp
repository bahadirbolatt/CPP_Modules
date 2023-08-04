#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template<typename T>
class Array
{
    private:
    T* elements;
    size_t len;

    public:
    Array(){
        len = 0;
        elements = nullptr;
        std::cout << "Array default constructor called\n";
    }

    Array(unsigned int size) : len(size){
        elements = new T[size];
        std::cout << "Array parameter constructor called\n";
    }

    Array(const Array &copy){
        len = copy.len;
        elements = new T[len];
        for(size_t i = 0; i < copy.len; i++)
            elements[i] = copy.elements[i];
        std::cout << "Array copy constructor called\n";
    }

    Array& operator=(const Array &copy){
        if(this == &copy)
            return(*this);
        delete[] elements;
        len = copy.len;
        elements = new T[len];
        for(size_t i = 0; i<len; i++)
            elements[i] = copy.elements[i];
        std::cout << "Array copy assignment operator called\n";
        return(*this);
    }
    ~Array(){
        delete[] elements;
        std::cout << "Array destructor called\n";
    }

    T& operator[](size_t index){
        if(index >= len)
            throw Array::outOfBounds();
        return(elements[index]);
    }

    unsigned int size() const{
        return(len);
    }

    class outOfBounds : public std::exception{
        public:
        const char *what() const throw(){
            return("\n <<< index is out of bounds >>> \n");
        }
    };
};

#endif