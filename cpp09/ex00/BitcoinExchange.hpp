#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

/*
Her modülde farklı bir STL container'ı kullanılmalıdır. ex02'de iki tane kullanabiliriz.
*/

#include <iostream>
#include <fstream>
#include <map>
#include <sstream>

class BitcoinExchange
{
    private:
        std::string fileName;
    public:
        BitcoinExchange();
        BitcoinExchange(std::string filename);
        BitcoinExchange& operator=(BitcoinExchange const &btc);
        ~BitcoinExchange();

        std::string getFileName() const;

        std::map<std::string, int> data;
        void addData();
};

#endif