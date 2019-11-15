# include "gameScene.h"

CS_Animation::CS_Animation()
{
    interrupt = NOINTERRUPT;
    index = 0;
}

CS_Animation::~CS_Animation()
{
    SDL_DestroyTexture(textureR);
    SDL_DestroyTexture(textureL);
}
