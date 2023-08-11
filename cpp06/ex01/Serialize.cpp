#include "Serialize.hpp"

Data::Data() : modelName("akinci"), modelYear(2020){
    // std::cout << "Data default constructor called" << std::endl;
}

Data::Data(std::string name, int year) : modelName(name), modelYear(year){
    // std::cout << "Data parameter constructor called" << std::endl;
}

Data::Data(const Data& dataCopy){
    if(this != &dataCopy)
    {
        modelName = dataCopy.modelName;
        modelYear = dataCopy.modelYear;
    }
    // std::cout << "Data copy constructor called" << std::endl;
}

Data& Data::operator=(const Data& dataCopy){
    // std::cout << "Data operator constructor called" << std::endl;
    if(this != &dataCopy)
    {
        modelName = dataCopy.modelName;
        modelYear = dataCopy.modelYear;
    }
    return *this;
}

Data::~Data(){
    // std::cout << "Data default constructor called" << std::endl;
}

std::string Data::getModelName(){
    return (this->modelName);
}
int Data::getModelYear(){
    return (this->modelYear);
}

void Data::print(){
    std::cout << "Vehicle's information printing..." << std::endl;
    std::cout << "Model : " + modelName << std::endl;
    std::cout << "Year : " << modelYear<< std::endl;
    std::cout << "Address : " << this << std::endl;
}

uintptr_t serialize(Data* ptr){
    // std::cout << "serialize function called" << std::endl;
    return reinterpret_cast<long long int>(ptr);
}

Data* deserialize(uintptr_t raw){
    // std::cout << "serialize function called" << std::endl;
    return reinterpret_cast<Data*>(raw);
}

// reinterpret_cast converts to data types