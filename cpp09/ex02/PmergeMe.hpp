#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <ctime>
#include <iomanip>


void printVector(const std::vector<int>& str);
void printList(const std::list<int> &str);

void mergesortForVector(std::vector<int> &input, std::vector<int> &right, std::vector<int> &left);
void mergeForVector(std::vector<int> &inputArray);

void mergesortForList(std::list<int> &input, std::list<int> &right, std::list<int> &left);
void mergeForList(std::list<int> &inputArray);

#endif