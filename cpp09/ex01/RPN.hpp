#ifndef RPN_HPP
#define RPN_HPP

#include "RPN.hpp"
#include <iostream>
#include <sstream>
#include <stack>

bool control(std::string str);
bool isOperator(char c);
int rpn(const std::string &rpnExpression);

#endif
