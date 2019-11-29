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
    delete MC;
    delete enemies;
    delete parallax;
    delete camera;
    delete assets;
}