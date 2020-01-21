# include "enemy.h"

void        CS_Enemies::updateID()
{
    unsigned long i;

    i = 0;
    while (i < enemies.size())
    {
        enemies[i]->setID(i);
        i++;
    }
}


void        CS_Enemies::updateEnemies(CS_Character *MC, int deltaT)
{
    unsigned long i;

    i = 0;
    while (i < enemies.size())
    {
        enemies[i]->setActionToUse(MC);
        enemies[i]->updateFrame(deltaT);
        enemies[i]->moveCharacter(deltaT);
        enemies[i]->getFrame();
        i++;
    }
}
