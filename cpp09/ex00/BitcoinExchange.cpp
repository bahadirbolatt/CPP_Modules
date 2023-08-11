#include "BitcoinExchange.hpp"

bool control(std::string line)
{
    if(count(line.begin(), line.end(), '|') < 1){
        std::cerr << "Error: bad input => " << line << std::endl;
        return false;
    }
    float number = std::strtof(line.substr(line.find('|') + 1, line.size()).c_str(), NULL);
    if(number < 0){
        std::cout << "Error: not a positive number." << std::endl;
        return false;
    }
    else if(number > 1000){
        std::cout << "Error: too large a number." << std::endl;
        return false;
    }
    return true;
}

void fillDb(std::map<std::string, double> &map)
{
    std::string data = "data.csv";
    std::ifstream ifs(data.c_str());
    std::string line;
    if(!ifs.is_open()){
        std::cerr << "Database cannot open!" << std::endl;
        return ;
    }
    std::getline(ifs, line);
    while(std::getline(ifs, line))
    {
        std::istringstream iss(line);
        std::string date, rate;
        getline(iss, date, ',');
        getline(iss, rate, '\0');
        map.insert(std::make_pair(date, std::stod(rate))); // push.back()
    }
}

void addData(const std::string &fileName){
    std::ifstream file(fileName.c_str());
    std::map<std::string, double> map;
    fillDb(map);
    if(!file.is_open())
    {
        std::cerr << "File cannot open!" << std::endl;
        return ;
    }
    std::string line;
    std::getline(file, line); // first line
    std::string date;
    std::string value;
    double exchange_rate;

    while(std::getline(file, line))
    {
        std::istringstream iss(line); // create a stream for line parsing 
        getline(iss, date, '|');
        getline(iss, value);
        exchange_rate = std::stod(value);
        if(!control(line))
            continue;
        for(std::map<std::string, double>::iterator it = map.begin(); it != map.end(); it++)
        {
            if(date.substr(0, date.size() - 1) == it->first){
                std::cout << date << " => " << exchange_rate << " = " << exchange_rate * it->second << std::endl;
                break;
            }
            else if(it->first > date){
                std::cout << date << " => " << exchange_rate << " = " << exchange_rate *(--it)->second << std::endl;
                break;
            }
        }
    }
    file.close();
}
