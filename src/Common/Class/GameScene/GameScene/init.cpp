# include "gameScene.h"

CS_GameScene::CS_GameScene()
{
//    enemies = new(CS_Enemies);
}

CS_GameScene::~CS_GameScene()
{
    delete MC;
    delete enemies;
    delete parallax;
    delete camera;
}