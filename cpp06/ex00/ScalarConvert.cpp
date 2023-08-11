#include "ScalarConvert.hpp"

ScalarConverter::ScalarConverter() : _c('c'), _i(3), _f(42.42f), _d(42.42){
    // std::cout << "ScalarConverter default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &src) : _c(src._c), _i(src._i), _f(src._f), _d(src._d) {
    // std::cout << "ScalarConverter copy constructor called" << std::endl;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &obj){
    if(this != &obj)
    {
        _c = obj._c;
        _i = obj._i;
        _f = obj._f;
        _d = obj._d;
    }
    // std::cout << "ScalarConverter assignment operator called" << std::endl;
    return (*this);
}

ScalarConverter::~ScalarConverter(){
    // std::cout << "ScalarConverter destructor called" << std::endl;
}

bool isLiteral(std::string &s)
{
    return (s == "nan" || s == "nanf" || s == "-inf" || s == "inf" || s == "+inf" || s == "-inff" || s == "inff" || s == "+inff");
}

static void convertToChar(std::string &str)
{
    char c;
    if(str.length() == 1)
        c = static_cast<char>(str[0]);
    else
        c = static_cast<int>(std::atoi(str.c_str()));
    if(isLiteral(str))
        std::cout << "impossible" << std::endl;
    else if(c < 32 || c > 126)
        std::cout << "Non-printing character" << std::endl;
    else
        std::cout << "'" << c << "'" << std::endl;
}

static void convertToInt(std::string &str)
{
    if(isLiteral(str))
        std::cout << "impossible" << std::endl;
    else if(str.length() == 1)
        std::cout << static_cast<int>(str[0]) << std::endl;
    else
        std::cout << std::atoi(str.c_str()) << std::endl;
}

static void convertToFloat(std::string &str)
{
    float number;
    if(str.length() == 1)
        number = static_cast<float  >(str[0]);
    else
        number = std::strtof(str.c_str(), NULL);
    if(number == static_cast<int>(number)) // tam sayi ise
        std::cout << number << ".0f" << std::endl;
    else
        std::cout << number << "f" << std::endl;
}

static void convertToDouble(std::string &str){
    double number;
    if(str.length() == 1)
        number = static_cast<double>(str[0]);
    else
        number = std::strtod(str.c_str(), NULL);
    if(number == static_cast<int>(number)) // tam sayi ise
        std::cout << number << ".0" << std::endl;
    else
        std::cout << number << std::endl;
}

bool isChar(std::string str)
{ 
    if(str.length() == 1 && isalpha(str[0]))
        return true;
    return false;
}
bool isInt(std::string str)
{
    for (size_t i = 0; i < str.length(); i++)
        if(!isdigit(str[i]))
            return false;
    return true;
}

bool isFloat(std::string str)
{
    // counting f, plus, minus and dot
    int fCount = std::count(str.begin(), str.end(), 'f');
    int pmCount = std::count(str.begin(), str.end(), '+') + std::count(str.begin(), str.end(), '-');
    int dotCount = std::count(str.begin(), str.end(), '.');

    // f + - check
    if(fCount != 1 || pmCount > 1 || dotCount != 1 || (fCount == 1 && str.back() != 'f'))
        return false;

    // dot check    
    if(dotCount == 1 && str[str.length() - 2] == '.')
        return false;

    // dot check
    if (!str.empty() && (str.front() == '.' || str.back() == '.'))
        return false;
    return true;
}

bool isDouble(std::string str)
{
    if(std::count(str.begin(), str.end(), 'f') > 0 || str[str.length() - 1] == '.')
        return false;
    if(std::count(str.begin(), str.end(), '.') != 1 || 
    (std::count(str.begin(), str.end(), '-') + std::count(str.begin(), str.end(), '+') > 1))
        return false;
    return true;
}

int getType(std::string str)
{
    for (size_t i = 0; i < str.size(); i++)
        if(!isChar(str) && !isLiteral(str) && !isdigit(str[i]) && str[0] != '+' && str[0] != '-' && str[i] != 'f' && str[i] != '.')
            return ERROR;
	if(isFloat(str))
		return(FLOAT);
    else if(isDouble(str))
		return(DOUBLE);
	else if(isChar(str))
		return(CHAR);
    else if(isLiteral(str))
        return(LITERAL);
	else if(isInt(str))
		return(INT);
	else
		return(ERROR);
}

void ScalarConverter::convert(std::string str)
{
    int status = getType(str);
    if(status == ERROR)
        throw ScalarConverter::error();
    else
    {
        std::cout << "char: ", convertToChar(str);
        std::cout << "int: ", convertToInt(str);
        std::cout << "float: ", convertToFloat(str);
        std::cout << "double: ", convertToDouble(str);
    }
}

bool isWrongNumber(std::string& str)
{
    size_t i;
    if(str[0] == '+' || str[0] == '-')
        if(std::count(str.begin(), str.end(), '-') + std::count(str.begin(), str.end(), '-') != 1)
            return true;
    if((std::count(str.begin(), str.end(), 'f') > 1 
    || std::count(str.begin(), str.end(), '.') > 1)
    || (std::count(str.begin(), str.end(), 'f') == 1
    && str[str.size() - 1] != 'f'))
        return true;
    for (i = 0; i < str.size(); i++)
        if(!isdigit(str[i]) && str[0] != '+' && str[i] != 'f' && str[i] != '.')
            return true;
    return false;
}

const char* ScalarConverter::error::what() const throw()
{
	return ("Error");
}