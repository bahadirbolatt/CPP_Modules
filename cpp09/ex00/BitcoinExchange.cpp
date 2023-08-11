#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}
BitcoinExchange::BitcoinExchange(std::string filename) : fileName(filename){} 
BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &btc){
    this->fileName = btc.getFileName();
    return (*this);
}
BitcoinExchange::~BitcoinExchange(){data.erase(data.begin(), data.end());}
std::string BitcoinExchange::getFileName() const{ return this->fileName;}

void BitcoinExchange::addData(){
    std::string fileName = this->fileName;
    std::ifstream file(fileName);

    if(file.is_open())
    {
        std::cerr << "File cannot open!" << std::endl;
        return ;
    }
    std::string line;
    std::getline(file, line); // first line

    while(std::getline(file, line))
    {
        std::istringstream iss(line); // create a stream for line parsing 
        std::string date;
        double exchange_rate;

        if(std::getline(iss, date, ',') && iss >> exchange_rate)
            this->data[date] = exchange_rate;
        else
            std::cerr << "Data cannot be read!" << std::endl;
    }
    file.close();
}