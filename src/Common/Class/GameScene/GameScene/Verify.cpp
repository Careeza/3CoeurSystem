# include "gameScene.h"

bool    CS_GameScene::haveMC()
{
    return(verifyMC);
}

bool    CS_GameScene::haveEnemies()
{
    return(verifyEnemies);
}

bool    CS_GameScene::haveParallax()
{
    return(verifyParallax);
}

bool            CS_GameScene::haveAssets()
{
    return(verifyAssets);
}
