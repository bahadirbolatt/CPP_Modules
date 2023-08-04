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
        elements = new T;
        std::cout << "Array default constructor called\n";
    }

    Array(const Array &copy){
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
        for(size_t i = 0; i<len; i++){
            elements[i] = copy.elements[i];
        }
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
    class outOfBounds : public std::exception{
        public:
        const char *what() const throw(){
            return("\n <<< index is out of bounds >>> \n");
        }
    };
};

#endif