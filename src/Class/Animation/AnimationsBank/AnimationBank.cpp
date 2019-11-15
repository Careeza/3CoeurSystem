# include "gameScene.h"

CS_BankAnimation::CS_BankAnimation()
{
}

CS_BankAnimation::~CS_BankAnimation()
{
    //TODO
}

void    addAnimation(SDL_Renderer *render, CS_Animation *(*f)(SDL_Renderer *render))
{
    f(render);
}
