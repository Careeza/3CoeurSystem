# include "gameScene.h"

void    CS_Enemies::reloadParam(int index, CS_Character *MC)
{
    CS_Enemy *enemy;

    enemy = enemies[index];
    enemy->reloadParam(MC);
}
