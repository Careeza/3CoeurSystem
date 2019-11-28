# include "gameScene.h"

CS_Character    *CS_GameScene::CS_queryMC()
{
    return (MC);
}

CS_Enemies      *CS_GameScene::CS_queryEnemies()
{
    return (enemies);
}

CS_Parallax      *CS_GameScene::QueryParallax()
{
    return (parallax);
}

CS_Camera      *CS_GameScene::QueryCamera()
{
    return (camera);
}