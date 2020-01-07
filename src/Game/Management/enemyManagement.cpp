#include "game.h"

void    enemyManagement(CS_Settings& settings)
{
    CS_Enemies      *enemies;
    CS_Enemy        *enemy;
    int i;

    enemies = settings.QueryGameScene()->QueryEnemies();
    i = 0;
    while (i < enemies->QueryNbEnemies())
    {
        enemy = enemies->QueryEnemy(i);
        enemy->reloadParam(settings.QueryGameScene()->QueryMC());
        enemy->getFrame();
        enemy->moveCharacter();
    i++;
    }
}