#include "easyfind.hpp"

int main()
{
    std::vector<int> vec(5, 42);
    for (size_t i = 0; i < vec.size(); i++)
        std::cout << "vec: " << vec.at(i) << std::endl;
    easyfind(vec, 42);
    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.pop_back();
    for(std::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
        std::cout << "lst: " <<*it << std::endl;
    easyfind(lst, 8);
    return 0;
}