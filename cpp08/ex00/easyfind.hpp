/*
Container -> vector, list, deque, map, set, stack, queue ...)
- at() = returns the param at the specified index. vec_int_item.at(0) = returns first param.
- front() = returns the elem. at the beggining of the vector.
- back() = returns the elem. at the end of the vector.
- swap() = swaps the elem. of the vector. For ex.
    vector<int> vect1(10,45); // 10 elements, 45 in it.
    vector<int> vect1(15); // 15 elements, null(0) in it.
    vect1.swap(vect2);
    After swap, the elements and size will change. So vect1's size and elewill change to 15 and vect2's size will change 10.
- push_back() = Adds the element to the end of vector.
- pop_back() = Erases the last elements of the vector.
- empty() = It returns a bool value whetether the vector is empty or not.
- insert() = Adds a new element at a specified index.
- erase() = Erases a element at a specified index.
- resize() = Changes the size of the vector.
- clear() = Clears the all elements of the vector.
- size() = Returns value of size the vector.
*/ 

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

template<typename T> void easyfind(T &vec, int i){
    if(std::find(vec.begin(), vec.end(), i) != vec.end())
        std::cout << i << " is found!\n";
    else
        std::cout << i << " is not found!\n";
}

#endif