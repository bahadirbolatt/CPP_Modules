#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <list>

class Span{
    private:
        unsigned int count;
        std::vector<int> vec;

    public:
        Span();
        Span(unsigned int N);
        Span(const Span& spanCopy);
        Span& operator=(const Span& spanCopy);
        ~Span();

        std::vector<int> &getVector();

        void addNumber(unsigned int number); // use for
        void addManyNumber(unsigned int number);
        void printData(void);

        int shortestSpan(void);
        int longestSpan(void);

        class noStorageLeft : public std::exception{const char *what() const throw();};
        class notEnoughNumbers : public std::exception{const char *what() const throw();};
};

#endif