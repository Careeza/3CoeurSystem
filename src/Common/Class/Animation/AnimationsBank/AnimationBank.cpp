# include "gameScene.h"

CS_BankAnimation::CS_BankAnimation()
{
}

CS_BankAnimation::~CS_BankAnimation()
{
    //TODO
}

void    CS_BankAnimation::addAnimation(SDL_Renderer *render, CS_Animation *(*f)(SDL_Renderer *render))
{
    CS_Animation    *animation;

    animation = f(render);
    animations.push_back(animation);
}