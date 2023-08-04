#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750

int main(){
    Array<int> emptyArray;
    std::cout << "Empty array size : " << emptyArray.size() << std::endl;

    std::cout << std::endl;
    //construction with unsigned int parameter
    Array<int> integerArray(5);
    std::cout << "integer array size : " << integerArray.size() << std::endl;

    // copy constructor
    std::cout << std::endl;
    Array<int> copyArray(integerArray);
    std::cout << "the copy of integerArray size : " << copyArray.size() << std::endl;

    //modify copyArray
    std::cout << std::endl;
    copyArray[2] = 100;
    std::cout << "intArray[2]: " << integerArray[2] << std::endl;
    std::cout << "copiedArray[2]: " << copyArray[2] << std::endl;

    //copy assignment array
    std::cout << std::endl;
    Array<int> assignmnetArray;
    assignmnetArray = integerArray;

    //modify it
    std::cout << std::endl;
    assignmnetArray[3] = 999;
    std::cout << "intArray[3]: " << integerArray[3] << std::endl;
    std::cout << "assignmentArray[3]: " << assignmnetArray[3] << std::endl;

    //index out of bounds test
    std::cout << std::endl;
    try{
        std::cout << "assignmentArray[6]: is not available" << assignmnetArray[6] << std::endl;
    }
    catch(const std::exception& e){
        std::cerr << e.what();
    }

    std::cout << std::endl;
    {
    Array<int> blockArray(10); // Örnek olarak 10 elemanlı bir dizi oluşturuyoruz.
    // blockArray'nin kullanılması
    // blockArray burada kapsam dışına çıkıyor ve bellekteki hafıza geri veriliyor.
    }
    Array<int>* intArrayPtr;
    intArrayPtr = new Array<int>(5);
    
    (*intArrayPtr)[0] = 10;
    (*intArrayPtr)[1] = 20;
    (*intArrayPtr)[2] = 30;
    (*intArrayPtr)[3] = 40;
    (*intArrayPtr)[4] = 50;
    
    std::cout << std::endl;
    // Dizi boyutuna erişim yapabiliriz.
    size_t size = intArrayPtr->size();
    std::cout << "Array size: " << size << std::endl;

    std::cout << std::endl;
    // Dizi elemanlarını ekrana yazdırabiliriz.
    for (size_t i = 0; i < size; i++) {
        std::cout << "Element " << i << ": " << (*intArrayPtr)[i] << std::endl;
    }
    delete intArrayPtr;
    //system("leaks Array");
}

// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }