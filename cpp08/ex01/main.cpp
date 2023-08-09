#include "Span.hpp"

int main()
{
    try
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "min distance: " << sp.shortestSpan() << std::endl;
        std::cout << "max distance: " << sp.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        Span sp = Span(100);
        sp.addManyNumber(100);
        sp.printData();
        std::cout << "\n";
        std::vector<int> vecc = sp.getVector();
        std::cout << vecc[99] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}