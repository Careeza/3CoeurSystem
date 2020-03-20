#include "gameScene.h"

CS_Layer::CS_Layer()
{
    scopeMain = new (SDL_Rect);
    scopeSecond = new (SDL_Rect);
    sizeMain = new (SDL_Rect);
    sizeSecond = new (SDL_Rect);
}

CS_Layer::~CS_Layer()
{
    delete  scopeMain;
    delete  scopeSecond;
    delete  sizeMain;
    delete  sizeSecond;
    SDL_DestroyTexture(layerTexture);
}
