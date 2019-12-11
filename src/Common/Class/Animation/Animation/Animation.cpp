# include "gameScene.h"s

CS_Animation::CS_Animation()
{
    Tools->verbose(LEVEL2, "s", "create animation");
    interrupt = NOINTERRUPT;
    index = 0;
    indexPas = 0;
    pas = 1;
}

CS_Animation::~CS_Animation()
{
    Tools->verbose(LEVEL2, "s", "delete animation");
    SDL_DestroyTexture(textureR);
    SDL_DestroyTexture(textureL);
}

void        CS_Animation::restartAnimation()
{
    index = 0;
}