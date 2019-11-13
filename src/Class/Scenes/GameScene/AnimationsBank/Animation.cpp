# include "gameScene.h"

CS_Animation::CS_Animation()
{
}

CS_Animation::~CS_Animation()
{
    SDL_DestroyTexture(textureR);
    SDL_DestroyTexture(textureL);
}

CS_BankAnimation::CS_BankAnimation()
{}

CS_BankAnimation::~CS_BankAnimation()
{
    //TODO
}