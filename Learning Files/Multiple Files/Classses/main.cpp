#include <iostream>
#include "Monster.h"

int main() 
{
    Monster monster {100};

    monster.takeDamage(50);

    std::cout << "The monsters damage is " << monster.getHp() << '\n';

    return 0;
}