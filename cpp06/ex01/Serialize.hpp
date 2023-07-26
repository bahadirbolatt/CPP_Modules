#ifndef SERIALIZE_HPP
#define SERIALIZE_HPP

#include <iostream>

class Data{
private:
    std::string modelName;
    int modelYear;
public:
    Data();
    Data(std::string name, int year);
    Data(const Data& dataCopy);
    Data& operator=(const Data& dataCopy);
    ~Data();

    std::string getModelName();
    int getModelYear();
    void print();
};

uintptr_t serialize(Data* ptr);   // data ptr to unsigned int
Data* deserialize(uintptr_t raw); // unsigned int to data ptr

#endif