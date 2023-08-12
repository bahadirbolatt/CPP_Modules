#include "PmergeMe.hpp"

int main(int argc, char *argv[]){
    if(argc == 1){
        std::cout << "Error : enter args more than 1!" << std::endl;
        return 1;
    }
    std::list<int> myList;
    std::vector<int> myVector;
    std::clock_t start;
    std::clock_t end;

    for (int i = 0; i < argc - 1; i++){
        if(std::atoi(argv[i + 1]) < 0){
            std::cout << "Error" << std::endl;
            return (1);
        }
        myList.push_back(std::atoi(argv[i + 1]));
        myVector.push_back(std::atoi(argv[i + 1]));
    }

    std::cout << "Before:  ";
    printList(myList);

    start = std::clock();
    mergeForList(myList);
    end = std::clock();
    double ListElapsed_time = double(end - start) / CLOCKS_PER_SEC * 1000;

    start = std::clock();
    mergeForVector(myVector);
    end = std::clock();
    double VecElapsed_time = double(end - start) / CLOCKS_PER_SEC * 1000;
    

    std::cout << std::endl << "After:   ";
    printVector(myVector);

    std::cout << std::endl << "Time to process a range of " << myList.size() << " elements with std::list<int>[..] : " << std::fixed << ListElapsed_time << " us" << std::endl;
    std::cout << "Time to process a range of " << myVector.size() << " elements with std::vector<int>[..] : " << std::fixed << VecElapsed_time << " us" << std::endl;
    return 0;
}