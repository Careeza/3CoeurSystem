#include "gameScene.h"

void    CS_GameScene::loadEnemies(CS_Enemies *enemiesSource)
{
    enemies = enemiesSource;
    verifyEnemies = true;
}

void    CS_GameScene::loadMC(CS_Character *MCSource)
{
    MC = MCSource;
    verifyMC = true;
}

void    CS_GameScene::loadParallax(CS_Parallax *parallaxSource)
{
    parallax = parallaxSource;
    verifyParallax = true;
}

void    CS_GameScene::loadAssets(CS_Assets *assetsSource)
{
    assets = assetsSource;
    verifyAssets = true;
}


void    CS_GameScene::loadCamera(CS_Camera *cameraSource)
{
    camera = cameraSource;
}

void    CS_GameScene::setBorneMap(float borneMinXSource, float borneMaxXSource)
{
    borneMaxX = Tools->transformWidth(borneMaxXSource);
    borneMinX = Tools->transformHeight(borneMinXSource);
}
