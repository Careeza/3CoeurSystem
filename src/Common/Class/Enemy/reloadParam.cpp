#include "gameScene.h"

void    CS_Enemy::reloadParam(CS_Character *MC)
{
    algo(enemy, MC);
}

void    CS_Enemy::getFrame()
{
    enemy->getFrame();
}

void    CS_Enemy::moveCharacter()
{
//    enemy->moveCharacter();
}