# include "enemy.h"

void        CS_Enemies::deleteEnemy(int index)
{
    enemies.erase(enemies.begin() + index);
    updateID();
}
