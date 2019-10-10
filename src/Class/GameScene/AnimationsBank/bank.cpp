# include "gameScene.h"

void        CS_BankAnimation::loadNoMove(SDL_Renderer *render)
{
    noMove = loadAnimation("noMove", render, "resources/source/MCNoMoveL.png", "resources/source/MCNoMoveR.png", 10, 10, 45, 45, 1, 1, 1);
}

void        CS_Character::loadBank(SDL_Renderer *render)
{
    bank->loadNoMove(render);
}