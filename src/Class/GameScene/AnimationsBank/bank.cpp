# include "gameScene.h"

void        CS_BankAnimation::loadNoMove(SDL_Renderer *render)
{
    noMove = initAnimation("noMove");
//    loadTexture(noMove, render, "resources/source/MCNoMoveL.png", "resources/source/MCNoMoveR.png");
    loadTexture(noMove, render, "resources/source/AllenWalkerL.png", "resources/source/AllenWalkerR.png");
//    setSize(noMove, 10, 10 * gameSettings.resolution, 45, 50 - (5 * gameSettings.resolution));
//    cutFrame(noMove, 1, 1, 1);
    cutFrame(noMove, 5, 5, 1);
}

void        CS_Character::loadBank(SDL_Renderer *render)
{
    bank->loadNoMove(render);
}