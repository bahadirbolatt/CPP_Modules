#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

// template'ler ile türden bağımsız kodlar yazabiliriz.
// Bu sayede farklı veri tipleri ile çalışan classlar ve codelar yazılabilir.

template<typename T> void swap(T &a, T &b){
    T tmp;
    tmp = a;
    a = b;
    b = tmp;
}

template<typename T> T& min(T &a, T &b){
    return((a < b) ? a : b); // Ternary condition operator
}

template<typename T> T& max(T &a, T &b){
    return((a > b) ? a : b);
}

#endif