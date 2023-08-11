#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

/*
Her modülde farklı bir STL container'ı kullanılmalıdır. ex02'de iki tane kullanabiliriz.
*/

#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <algorithm>

void addData(const std::string &fileName);
bool control(std::string line);
void fillDb(std::map<std::string, double> &map); // eger & göndermeseydik map in bir kopyası oluşup giderdi o yüzden adres aldik.

#endif