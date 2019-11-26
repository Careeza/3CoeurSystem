# include "gameScene.h"

CS_BankAnimation::CS_BankAnimation()
{
    Tools->verbose(LEVEL2, "s", "create bank animation");
}

CS_BankAnimation::~CS_BankAnimation()
{
    //TODO
    Tools->verbose(LEVEL2, "s", "delete bank animation");
}

void    CS_BankAnimation::addAnimation(SDL_Renderer *render, CS_Animation *(*f)(SDL_Renderer *render))
{
    CS_Animation    *animation;

    animation = f(render);
    animations.push_back(animation);
}