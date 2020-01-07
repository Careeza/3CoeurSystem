# include "gameScene.h"

SDL_Texture *CS_Character::QueryTexture()
{
    return (texture);
}

void    CS_Character::QuerySizePos(int& wDest, int& hDest, int& xDest, int& yDest)
{
    animation->QuerySize(wDest, hDest);
    physic->QueryPostion(xDest, yDest);
}

CS_PersonalPhysic   *CS_Character::QeuryPhysique()
{
    return (physic);
}


void    CS_Character::QuerySize(int& wDest, int& hDest)
{
    animation->QuerySize(wDest, hDest);
}

void    CS_Character::QueryPos(int& xDest, int& yDest)
{
    physic->QueryPostion(xDest, yDest);
}


SDL_Rect    *CS_Character::QueryFrame()
{
    return (frame);
}

int         CS_Character::QueryMoveX()
{
    return (animation->QueryMovementX(right));
}