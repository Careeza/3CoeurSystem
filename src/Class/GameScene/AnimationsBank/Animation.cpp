# include "gameScene.h"

CS_Animation::CS_Animation()
{
    size = new(SDL_Rect);
}

CS_Animation::~CS_Animation()
{
    delete size;
    SDL_DestroyTexture(textureR);
    SDL_DestroyTexture(textureL);
}