# include "gameScene.h"

SDL_Texture *CS_Character::QueryTexture()
{
    return (texture);
}

CS_PersonalPhysic   *CS_Character::QueryPhysic()
{
    return (physic);
}

void    CS_Character::QuerySizePos(int& wDest, int& hDest, int& xDest, int& yDest)
{
    animation->QuerySize(wDest, hDest);
    physic->QueryPostion(xDest, yDest);
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

CS_Animation    *CS_Character::QueryAnimation()
{
    return (animation);
}
