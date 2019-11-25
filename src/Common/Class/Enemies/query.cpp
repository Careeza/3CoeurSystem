# include "gameScene.h"

CS_Enemy    *CS_Enemies::QueryEnemy(int index)
{
    return (enemies[index]);
}

int         CS_Enemies::QueryNbEnemies()
{
    return (enemies.size());
}