#include "gameScene.h"

CS_Character::CS_Character()
{
    std::cout << "create a character" << std::endl;
    saveAnimation = NULL;
    bank = new (CS_BankAnimation);
    right = false;
}

CS_Character::~CS_Character()
{
    std::cout << "delete a character" << std::endl;
    delete bank;
}

SDL_Texture *CS_Character::queryTexture()
{
    return (texture);
}

void    CS_Character::querySizePos(int& wSource, int& hSource, int& xSource, int& ySource)
{
    wSource = w;
    hSource = h;
    xSource = x;
    ySource = y;
}

void    CS_Character::querySize(int& wSource, int& hSource)
{
    wSource = w;
    hSource = h;
}

void    CS_Character::queryPos(int& xSource, int& ySource)
{
    xSource = x;
    ySource = y;
}


SDL_Rect    *CS_Character::queryFrame()
{
    return (frame);
}

int         CS_Character::queryMoveX()
{
    return (animation->QueryMovementX(right));
}