# include "gameScene.h"

void        CS_BankAnimation::loadNoMove(SDL_Renderer *render)
{
    int h;
    int y;
    
    h = 10 * gameSettings.resolution;
    y = 50 - h / 2;
    noMove = loadAnimation("noMove", render, "resources/source/MCNoMoveL.png", "resources/source/MCNoMoveR.png", 10, h, 45, y, 1, 1, 1);
}

void        CS_Character::loadBank(SDL_Renderer *render)
{
    bank->loadNoMove(render);
}