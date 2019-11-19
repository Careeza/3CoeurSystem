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

void    CS_Settings::initScene(SDL_Renderer *render)
{
    Scene = init_home(render);
}

void    CS_Settings::initGameScene(SDL_Renderer *render)
{
    gameScene = init_gameScene(render);
}
