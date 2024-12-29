#include "Monster.h"

Monster::Monster(int hp) {
    mHp = hp;
}

int Monster::getHp() {
    return mHp;
}

void Monster::takeDamage(int damage){
    mHp-=damage;

    if (mHp < 0){
        mHp = 0;
    }
}