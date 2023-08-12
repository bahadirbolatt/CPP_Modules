#include "BitcoinExchange.hpp"

bool control(std::string line, float number)
{
    if(count(line.begin(), line.end(), '|') < 1){
        std::cerr << "Error: bad input => " << line << std::endl;
        return false;
    }
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

void fillDb(std::map<std::string, float> &map)
{
    std::string data = "data.csv";
    std::ifstream ifs(data);
    std::string line;
    if(!ifs.is_open()){
        std::cerr << "Database cannot open!" << std::endl;
        return ;
    }
    std::getline(ifs, line);
    while(std::getline(ifs, line))
    {
        std::string date = line.substr(0, line.find(','));
        float rate = std::stof(line.substr(line.find(',') + 1, line.size()));
        map.insert(std::make_pair(date, rate)); // push back 
    }
}

void addData(const std::string &fileName){
    std::ifstream file(fileName);
    std::map<std::string, float> map;
    fillDb(map);
    if(!file.is_open())
    {
        std::cerr << "File cannot open!" << std::endl;
        return ;
    }
    std::string line;
    std::getline(file, line); // first line
    std::string date;
    float exchange_rate;

    while(std::getline(file, line))
    {
        date = line.substr(0, line.find('|') - 1);
        exchange_rate = std::stof(line.substr(line.find('|') + 1, line.size()));
        if(!control(line, exchange_rate))
            continue;
        std::map<std::string, float>::iterator it = map.find(date);
        std::map<std::string, float>::iterator it_equal = map.lower_bound(date);
        if(it != map.end())
            std::cout << date << " => " << exchange_rate << " = " << exchange_rate * it->second << std::endl;
        else if(it_equal != map.end())
            std::cout << date << " => " << exchange_rate << " = " << exchange_rate *(--it_equal)->second << std::endl;
    }
    file.close();
}
