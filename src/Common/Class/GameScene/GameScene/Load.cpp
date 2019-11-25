#include "gameScene.h"

void    CS_GameScene::loadEnemies(CS_Enemies *enemiesSource)
{
    enemies = enemiesSource;
}

void    CS_GameScene::loadMC(CS_Character *MCSource)
{
    MC = MCSource;
}