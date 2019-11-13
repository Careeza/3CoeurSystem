#include "gameScene.h"

void    CS_GameScene::loadMC()
{
    MC->loadBank(render);
}

void    CS_GameScene::loadEnemies()
{
    enemies->addEnemy(CubeRouge, render);
    enemies->addEnemy(CuveVert, render);
    enemies->addEnemy(CubeRouge, render);
}