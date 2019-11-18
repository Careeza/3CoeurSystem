# include "gameScene.h"


void        CS_Character::addAnimation(SDL_Renderer *render, CS_Animation*(*f)(SDL_Renderer *render))
{
    bank->addAnimation(render, f);
}