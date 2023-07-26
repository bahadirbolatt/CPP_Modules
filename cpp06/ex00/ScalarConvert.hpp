#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>

enum v_type
{
    INT,
    FLOAT,
    CHAR,
    DOUBLE,
    LITERAL,
    ERROR
};

class ScalarConverter
{
    private:
        char    _c;
        int     _i;
        float   _f;
        double  _d;
    public:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &src);
        ScalarConverter& operator=(const ScalarConverter &obj);
        ~ScalarConverter();

        static void convert(std::string str);
        class error : public std::exception
        {
            const char* what() const throw();
        };
};
        int getType(std::string str);
        bool isLiteral(std::string &s);
        bool isWrongNumber(std::string& str);

#endif