# ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
    public:
        Weapon *weapon;
        std::string name;
        void attack(void);
        HumanB(std::string name);
        void setWeapon(Weapon &weapon);
        ~HumanB();
};
#endif