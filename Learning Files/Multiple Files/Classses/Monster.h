#ifndef MONSTER
#define MONSTER

class Monster
{
    private:
        int mHp;

    public:
        Monster(int hp);
        int getHp();
        void takeDamage(int damage);
};

#endif