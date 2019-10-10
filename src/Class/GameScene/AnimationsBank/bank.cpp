# include "gameScene.h"

void        CS_BankAnimation::loadNoMove(SDL_Renderer *render)
{
    noMove = loadAnimation("noMove", render, "resources/source/MCFix2.png ", "resources/source/MCFix1.png ", 10, 10, 45, 45, 1, 1, 1);
}

void        CS_Character::loadBank(SDL_Renderer *render)
{
    bank->loadNoMove(render);
}