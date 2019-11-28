#include "game.h"

CS_Settings::CS_Settings()
{
    closeRequested = false;
    pauseRequested = false;
    fps = 60;
}

CS_Settings::~CS_Settings()
{
    
}

void    CS_Settings::initScene(CS_Scene *sceneSource)
{
    Scene = sceneSource;
}

void    CS_Settings::initGameScene(CS_GameScene *gameSceneSource)
{
    gameScene = gameSceneSource;
}
