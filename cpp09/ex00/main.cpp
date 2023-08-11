#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    std::ifstream ifs(av[1]);
    if(ac != 2)
        std::cerr << "Error: could not open file." << std::endl;
    else
    {
        if(!ifs.is_open())
        {
            std::cerr << "File cannot open!" << std::endl;
            return (1);
        }
    }
    std::map<std::string, int> myDb;
    myFunc(myDb, ifs);
    return (0);
}