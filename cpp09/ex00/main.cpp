#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <map>

int main(int ac, char **av) {
    if (ac != 2) {
        std::cerr << "Hata: argüman eksik!" << std::endl;
        return 1;
    }
    addData(av[1]);
    return 0;
}
