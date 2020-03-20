#include "projectile.h"

void                CS_Projectile::initPhysicProjectile(CS_PersonalPhysic *physicSource)
{
    physic = physicSource;
}

void                CS_Projectile::initAnimation(CS_Animation *animationSource)
{
    animation = animationSource;
}

void                CS_Projectile::setName(t_projectile nameSource)
{
    name = nameSource;
}

void                CS_Projectile::setID(int idSource)
{
    id = idSource;
}

void                CS_Projectile::setRight(int rightSource)
{
    right = rightSource;
}

void                CS_Projectile::setRange(int rangeSource)
{
    range = rangeSource;
}

void                CS_Projectile::setAlly(bool allySource)
{
    ally = allySource;
}
