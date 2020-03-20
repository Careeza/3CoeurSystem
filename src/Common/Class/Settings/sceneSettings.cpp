#include "game.h"

void            CS_Settings::getScene(CS_Scene *sceneSource)
{
    delete Scene;
    Scene = sceneSource;
}

void            CS_Settings::getGameScene(SDL_Renderer *render)
{
    (void)render;
}
