#include "projectile.h"

void                CS_Projectile::QuerySizePos(int& wDest, int& hDest, int& xDest, int& yDest)
{
    animation->QuerySize(wDest, hDest);
    physic->QueryPostion(xDest, yDest);
}

void                CS_Projectile::QuerySize(int& wDest, int& hDest)
{
    animation->QuerySize(wDest, hDest);
}

void                CS_Projectile::QueryPos(int& xDest, int& yDest)
{
    physic->QueryPostion(xDest, yDest);
}


int                 CS_Projectile::QueryID()
{
    return (id);
}

t_projectile        CS_Projectile::QueryName()
{
    return (name);
}

CS_Animation        *CS_Projectile::QueryAnimation()
{
    return (animation);
}

CS_PersonalPhysic   *CS_Projectile::QueryPhysic()
{
    return (physic);
}

SDL_Texture         *CS_Projectile::QueryTexture()
{
    return (texture);
}

SDL_Rect            *CS_Projectile::QueryFrame()
{
    return (frame);
}

int                 CS_Projectile::QueryRange()
{
    return (range);
}

bool                CS_Projectile::QueryAlly()
{
    return (ally);
}
