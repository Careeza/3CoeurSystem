#include "scene.h"

CS_Brightness::CS_Brightness()
{
    rect = new (SDL_Rect);
}

CS_Brightness::~CS_Brightness()
{
    delete rect;
}

void            CS_Brightness::destroyTexture()
{
    SDL_DestroyTexture(texture);
}
