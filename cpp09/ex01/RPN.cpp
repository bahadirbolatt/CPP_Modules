#include "RPN.hpp"

bool control(std::string str)
{
    for(unsigned long i = 0; i < str.length(); i++){
        if(std::isspace(str[i]))
            return true;
        else if(!isdigit(str[i]) && !isOperator(str[i]))
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
    char token;
    unsigned int i = 0;
    if(!control(str)){
        std::cout << "Error" << std::endl;
        return INT_MIN;
    }  
    while(i < str.size())
    {
        token = str[i];
        if(std::isdigit(token)){
            operands.push(token - '0');
        }
        else if(isOperator(token))
        {
            int op1 = operands.top(); operands.pop();
            int op2 = operands.top(); operands.pop();
            int res = calculate(op1, op2, token);
            operands.push(res);
        }
        i++;
    }
    return operands.top();
}