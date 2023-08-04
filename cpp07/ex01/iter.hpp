#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename t> void iter(t* variable, unsigned int len, void func(t &arg)){
    for(unsigned int i = 0; i<len; i++){
        func(variable[i]);
    }
}

template<typename t> void call(t& a){
    std::cout << a << " : "<< "Biz Teknofest'le büyüdük 🎵\n";
}

#endif