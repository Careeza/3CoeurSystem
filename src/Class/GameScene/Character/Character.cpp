#include "gameScene.h"

CS_Character::CS_Character()
{
    bank = new (CS_BankAnimation);
    size = new (SDL_Rect);
    right = false;
}

CS_Character::~CS_Character()
{
    delete bank;
    delete size;
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