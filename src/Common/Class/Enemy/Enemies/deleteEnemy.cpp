# include "enemy.h"

void        CS_Enemies::deleteEnemy(int index)
{
    enemies.erase(enemies.begin() + index);
    updateID();
}

void        CS_Enemies::deleteAllEnemy()
{
    unsigned long i;

    i = 0;
    while (i < enemies.size())
    {
        deleteEnemy(i);
    }
}
