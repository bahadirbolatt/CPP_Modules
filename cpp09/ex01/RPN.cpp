#include "RPN.hpp"

bool control(std::string str)
{
    for(size_t i = 0; i < str.length(); i++)
    {
        char c = str[i];
        if(std::isspace(c))
            continue;
        if(!isdigit(c) && !isOperator(c))
            return false;
    }
    return true;
}


bool isOperator(char c){
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int calculate(int op1, int op2, char op)
{
    switch (op)
    {
        case '+':
            return op1 + op2;
        case '-':
            return op2 - op1;
        case '*':
            return op1 * op2;
        case '/':
            return op1 / op2;
        default:
            return 0; // invalid op
    }
}

int rpn(const std::string& str)
{
    std::stack<int> operands;
    std::istringstream ss(str);
    std::string token;
    if(!control(str)){
        std::cout << "Error" << std::endl;
        return 0;
    }  
    while(ss >> token)
    {
        if(std::isdigit(token[0])){
            operands.push(std::stoi(token));
        }
        else if(isOperator(token[0]))
        {
            int op1 = operands.top(); operands.pop();
            int op2 = operands.top(); operands.pop();
            int res = calculate(op1, op2, token[0]);
            operands.push(res);
        }
    }
    std::cout << operands.top() << std::endl;
    return 0;
}