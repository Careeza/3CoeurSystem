#include "projectile.h"

void                CS_Projectile::updateFrame(int deltaT)
{
    animation->nextFrame2(deltaT);
    range -= deltaT;
}

void                CS_Projectile::moveProjectile(int deltaT)
{
//    physic->updatePosition(deltaT);
}

void                CS_Projectile::getFrame()
{
    texture = animation->QueryTexture(right);
    frame = animation->QueryFrame();
}

bool                CS_Projectile::projectileEnd()
{
    return (range <= 0);
}
