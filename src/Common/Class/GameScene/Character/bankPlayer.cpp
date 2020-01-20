# include "gameScene.h"


void        CS_Character::addAnimation(SDL_Renderer *render, CS_Animation*(*f)(SDL_Renderer *render))
{
    if (moine)
        bankMoine->addAnimation(render, f);
    else
        bankKitsune->addAnimation(render, f);
}