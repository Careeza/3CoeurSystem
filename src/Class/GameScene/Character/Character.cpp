#include "gameScene.h"

CS_Character::CS_Character()
{
    bank = new (CS_BankAnimation);
    i = 0;
    right = false;
    endAnimation = false;
}

CS_Character::~CS_Character()
{
    delete bank;
}

SDL_Texture *CS_Character::queryTexture()
{
    return (texture);
}

SDL_Rect    *CS_Character::querySize()
{
    return (size);
}

SDL_Rect    *CS_Character::queryFrame()
{
    return (frame);
}