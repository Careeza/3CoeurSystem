#include "gameScene.h"

void    CS_GameScene::loadEnemies(CS_Enemies *enemiesSource)
{
    enemies = enemiesSource;
}

void    CS_GameScene::loadMC(CS_Character *MCSource)
{
    MC = MCSource;
}

void    CS_GameScene::loadParallax(CS_Parallax *parallaxSource)
{
    parallax = parallaxSource;
}

void    CS_GameScene::loadCamera(CS_Camera *cameraSource)
{
    camera = cameraSource;
}
