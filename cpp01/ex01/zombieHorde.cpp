#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
    Zombie *zombies = new Zombie[N];

    int i = 0;
    while(N > 0)
    {
        zombies[i].setName(name);
        zombies[i].getName();
        zombies[i].announce(name);
        N--;
        i++;
    }
    return(zombies);
}