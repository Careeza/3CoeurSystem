# include "gameScene.h"

CS_Animation::CS_Animation()
{
    Tools->verbose(LEVEL2, "s", "create animation");
    animationEnd = false;
    interrupt = false;
    index = 0;
    time = 0;
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
    time = 0;
}
