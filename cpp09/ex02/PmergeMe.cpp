#include "PmergeMe.hpp"

void printVector(const std::vector<int> &str){
    for (size_t i = 0; i < str.size(); i++){
        (i == str.size() - 1)?std::cout << str[i]:std::cout << str[i] << " ";
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
    int inputLength = inputArray.size();
    if(inputLength < 2)
        return ;
    
    int midIndex = inputLength / 2;
    std::vector<int> leftHalf(midIndex);
    std::vector<int> rightHalf(inputLength - midIndex);

    for(int i = 0; i < midIndex; i++){
        leftHalf[i] = inputArray[i];
    }
    for(int i = midIndex; i < inputLength; i++){
        rightHalf[i - midIndex] = inputArray[i];
    }

    mergeForVector(leftHalf);
    mergeForVector(rightHalf);

    mergesortForVector(inputArray, rightHalf, leftHalf);
}

void mergesortForList(std::list<int> &input, std::list<int> &right, std::list<int> &left){
    std::list<int>::iterator itInput = input.begin();
    std::list<int>::iterator itRight = right.begin();
    std::list<int>::iterator iteRightEnd = right.end();
    std::list<int>::iterator itLeft = left.begin();
    std::list<int>::iterator itLeftEnd = left.end();
    
    for (; itRight != iteRightEnd && itLeft != itLeftEnd;)
    {
        if(*itRight <= *itLeft){
            *itInput = *itRight;
            itRight++;
        }
        else{
            *itInput = *itLeft;
            itLeft++;
        }
        itInput++;
    }
    while(itRight != iteRightEnd){
        *itInput = *itRight;
        itInput++;
        itRight++;
    }
    while(itLeft != itLeftEnd){
        *itInput= *itLeft;
        itInput++;
        itLeft++;
    }
}

void mergeForList(std::list<int> &inputArray)
{
    std::list<int>::iterator itInput = inputArray.begin();
    int inputLength = inputArray.size();
    if(inputLength < 2)
        return;
    int midIndex = inputLength / 2;
    std::list<int> leftHalf(midIndex);
    std::list<int> rightHalf(inputLength - midIndex);

    std::list<int>::iterator itLeft = leftHalf.begin();

    std::list<int>::iterator itRight = rightHalf.begin();

    for(unsigned long i = 0; i < leftHalf.size(); i++){
        *itLeft = *itInput;
        itLeft++;
        itInput++;
    }
    for(int i = midIndex; i < inputLength; i++){
        *itRight = *itInput;
        itRight++;
        itInput++;
    }
    mergeForList(leftHalf);
    mergeForList(rightHalf);

    mergesortForList(inputArray, rightHalf, leftHalf);
}