#include "PmergeMe.hpp"

void printVector(const std::vector<int> &str){
    for (size_t i = 0; i < str.size(); i++){
        (i == str.size() - 1)?std::cout << str[i]:std::cout << str[i] << " ";
    }
}

void mergesortForVector(std::vector<int> &input, std::vector<int> &right, std::vector<int> &left){
    unsigned long i,j,k;
    for (i = 0, j = 0, k = 0; i < right.size() && j < left.size();)
    {
        if(right[i] <= left[j])
            input[k] = right[i++];
        else
            input[k] = left[j++];
        k++;
    }
    while(i < right.size())
        input[k++] = right[i++];
    while(j < left.size())
        input[k++] = left[j++];
}

void mergeForVector(std::vector<int> &inputArray){
    int inputLenght = inputArray.size();
    if(inputLenght < 2)
        return ;
    
    int midIndex = inputLenght / 2;
    std::vector<int> leftHalf(midIndex);
    std::vector<int> rightHalf(inputLenght - midIndex);

    for(int i = 0; i < midIndex; i++){
        leftHalf[i] = inputArray[i];
    }
    for(int i = midIndex; i < inputLenght; i++){
        rightHalf[i - midIndex] = inputArray[i];
    }

    mergeForVector(leftHalf);
    mergeForVector(rightHalf);

    mergesortForVector(inputArray, rightHalf, leftHalf);
}

void printList(const std::list<int> &str){
    std::list<int>::const_iterator it = str.begin();
    std::list<int>::const_iterator ite = str.end();
    while(it != ite){
        std::cout << *it << " ";
        it++;
    }
}

void printList(const std::list<int> &str){
    std::list<int>::const_iterator it = str.begin();
    std::list<int>::const_iterator ite = str.end();
    while(it != ite){
        std::cout << *it << " ";
        it++;
    }
}

void mergeForList(std::list<int> &inputArray){
    std::list<int>::iterator itInput1 = inputArray.begin();
    std::list<int>::iterator itInput2 = inputArray.end();
}