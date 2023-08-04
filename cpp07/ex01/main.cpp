#include "iter.hpp"

int main(){
    int numbers[5] = {1,2,3,4,5};
    std::string str[5] = {"bahadir", "zeynep", "oguz", "zehra", "tansel"};

    // Fonksiyon şablonunu çağırma
    ::iter(numbers, 5, call);
    std::cout << std::endl;
    ::iter(str, 4, call);
    // Çıktı: 1 4 9 16 25
}