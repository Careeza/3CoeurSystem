# include "gameScene.h"

CS_GameScene::CS_GameScene()
{
    verifyMC = false;
    verifyEnemies = false;
    verifyParallax = false;
    verifyAssets = false;
}

CS_GameScene::~CS_GameScene()
{
    if (haveMC())
        delete MC;
    if (haveEnemies())
        delete enemies;
    if (haveParallax())
        delete parallax;
    if (haveAssets())
        delete assets;
    delete camera;
}