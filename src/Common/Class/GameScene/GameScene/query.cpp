# include "gameScene.h"

CS_Character    *CS_GameScene::QueryMC()
{
    return (MC);
}

CS_Enemies      *CS_GameScene::QueryEnemies()
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

CS_Assets       *CS_GameScene::QueryAssets()
{
    return (assets);
}

void            CS_GameScene::QueryBorne(int& borneMinXDest, int& borneMaxXDest)
{
    borneMaxXDest = borneMaxX;
    borneMinXDest = borneMinX;
}