#include "RPN.hpp"

/*  
    Reverse Polish Notation (RPN) is a notation for mathematical expressions in which operators are placed before operands. This notation allows expressions to be ordered without the need for parentheses and operator precedence. Reverse Polish Notation is used in pocket calculators and some computing devices.
    For example, consider a simple mathematical expression:    Geleneksel İfade: 3 + 4 * 5
    RPN: 3 4 5 * +
*/

int main(int ac, char **av)
{
    if(ac != 2){
        std::cerr << "Arg error!" << std::endl;
        return (1);
    }
    if(!valid(av[1])){
        std::cout << "Error" << std::endl;
        return (1);
    }
}