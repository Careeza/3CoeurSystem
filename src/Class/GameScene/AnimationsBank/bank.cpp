# include "gameScene.h"

void        CS_BankAnimation::loadNoMove(SDL_Renderer *render)
{
    noMove = initAnimation("noMove");
    loadTexture(noMove, render, "resources/source/MCNoMoveL.png", "resources/source/MCNoMoveR.png");
    cutFrame(noMove, 1, 1, 1);
    setMovement(noMove, 1, 0.0);
}

void        CS_BankAnimation::loadAllenWalker(SDL_Renderer *render)
{
    AllenWalker = initAnimation("AllenWalker");
    loadTexture(AllenWalker, render, "resources/source/AllenWalkerL.png", "resources/source/AllenWalkerR.png");
    cutFrame(AllenWalker, 5, 5, 1);
    setMovement(AllenWalker, 5, 1.0, 1.0, 1.0, 1.0, 1.0);
}

void        CS_Character::loadBank(SDL_Renderer *render)
{
    bank->loadNoMove(render);
}